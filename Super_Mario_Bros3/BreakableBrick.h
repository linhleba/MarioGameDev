#pragma once
#include "GameObject.h"
#include "algorithm"
#include "Mario.h"
#include "PlayScence.h"
#include "Coin.h"

#define BREAKABLE_BRICK_BBOX_WIDTH		16
#define BREAKABLE_BRICK_BBOX_HEIGHT		16

#define BREAKABLE_BRICK_STATE_NORMAL	0
#define BREAKABLE_BRICK_STATE_BREAK		100
#define BREAKABLE_BRICK_STATE_COIN		200



#define BREAKABLE_BRICK_ANI_NORMAL		0
#define BREAKABLE_BRICK_ANI_COIN		1


class CBreakableBrick : public CGameObject
{
	DWORD reviveTime=0;
	bool isRevive = false;
public:
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	CBreakableBrick();
	void StartRevive()
	{
		reviveTime = GetTickCount();
	}
	virtual void SetState(int state);
	bool GetIsRevive()
	{
		return isRevive;
	}
	void SetIsRevive(bool IsReviveBool)
	{
		isRevive = IsReviveBool;
	}

	
};