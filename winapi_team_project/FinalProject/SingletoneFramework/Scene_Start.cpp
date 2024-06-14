#include "pch.h"
#include "CCore.h"
#include "Scene_Start.h"

#include "CStartScreen.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CText.h"

#include "CColliderMgr.h"
#include "CKeyMgr.h"
#include "CPathMgr.h"
#include "CTexture.h"
#include "CSceneMgr.h"
#include "CCamera.h"

Scene_Start::Scene_Start() 
{
}

Scene_Start::~Scene_Start() 
{
}

void Scene_Start::Update() {
	CScene::Update();

	if (KEY_TAP(KEY::ENTER)) {
		// 0.5초 반 검은색 화면 0.5초 완전 검은색 화면
		ChangeScene(SCENE_TYPE::STAGE_01);
	}
}

void Scene_Start::Enter() {
	CObject* startScreen = new CStartScreen;
	AddObject(startScreen, GROUP_TYPE::MAP);

	CObject* PressEnterString = new CText;
	AddObject(PressEnterString, GROUP_TYPE::TEXT);
}

void Scene_Start::Exit() {
	DeleteAll();
}