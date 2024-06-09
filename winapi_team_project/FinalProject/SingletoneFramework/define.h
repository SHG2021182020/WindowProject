#pragma once
#include "pch.h"

#define SINGLE(type) public:\
		static type* Instance()\
		{\
		static type mgr;\
		return &mgr;\
		}\
		private:\
			type();\
			~type();
#define fDT CTimeMgr::Instance()->getfDT()
#define DT CTimeMgr::Instance()->getDT()

#define KEY_CHECK(key, state)CKeyMgr::Instance()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY) 
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP) 
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define PI 3.1415926535f

enum class GROUP_TYPE {
	MAP,
	DEFAULT,
	PLAYER,
	MISSTILE,
	MONSTER,

	END = 32,
};

enum class SCENE_TYPE {
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};

enum class BRUSH_TYPE {
	HOLLOW,
	END,
};

enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	END,
};