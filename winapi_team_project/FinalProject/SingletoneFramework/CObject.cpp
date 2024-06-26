#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CCollider.h"
#include "CFinding.h"
#include "CAnimator.h"

CObject::CObject()
	: ptPos{}
	, ptScale{}
	, collider(nullptr)
	, finding(nullptr)
	, animator(nullptr)
	, alive(true)
	, Selection(1)
{
}

CObject::CObject(const CObject& _origin)
	: strName(_origin.strName)
	, ptPos(_origin.ptPos)
	, ptScale(_origin.ptScale)
	, collider(nullptr)
	, finding(nullptr)
	, animator(nullptr)
	, alive(true)
	, Selection(1)
{
	if (_origin.collider) {
		collider = new CCollider(*_origin.collider);
		collider->owner = this;
	}

	if (_origin.finding) {
		finding = new CFinding(*_origin.finding);
		finding->owner = this;
	}

	if (_origin.animator) {
		animator = new CAnimator(*_origin.animator);
		animator->owner = this;
	}
}

CObject::~CObject() {
	if (nullptr != collider)
		delete collider;

	if (nullptr != finding)
		delete finding;

	if (nullptr != animator) {
		delete animator;
	}
}

void CObject::Render(HDC _hDC) {
	Vec2 RenderPos = CCamera::Instance()->GetRenderPos(ptPos);
	Vec2 ptScale = getScale();

	Rectangle(_hDC
		, RenderPos.x - ptScale.x / 2
		, RenderPos.y - ptScale.y / 2
		, RenderPos.x + ptScale.x / 2
		, RenderPos.y + ptScale.y / 2);

	CommponentRender(_hDC);
}

void CObject::FinalUpdate() {
	if (collider)
		collider->FinalUpdate();
	if (finding)
		finding->FinalUpdate();
}

void CObject::CommponentRender(HDC _hDC) {
	if (nullptr != collider)
		collider->Render(_hDC);

	if (nullptr != finding)
		finding->Render(_hDC);

	if (nullptr != animator) {
		animator->Render(_hDC);
	}
}

void CObject::CreateCollider() {
	collider = new CCollider;
	collider->owner = this;
}

void CObject::CreateFinding() {
	finding = new CFinding;
	finding->owner = this;
}

void CObject::CreateAnimator() {
	animator = new CAnimator;
	animator->owner = this;
}