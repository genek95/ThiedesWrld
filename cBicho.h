#pragma once

#include "cScene.h"

#define STEP_LENGTH	  (TILE_SIZE/8)

#define STATE_LOOKUP		1
#define STATE_LOOKRIGHT		2
#define STATE_LOOKDOWN		3
#define STATE_LOOKLEFT		4

#define STATE_WALKUP		6
#define STATE_WALKRIGHT		7
#define STATE_WALKDOWN		8
#define STATE_WALKLEFT		9

#define STATE_DAMAGEUP		10
#define STATE_DAMAGERIGHT	11
#define STATE_DAMAGEDOWN	12
#define STATE_DAMAGELEFT	13

#define STATE_ATTACKUP		14
#define STATE_ATTACKRIGHT	15
#define STATE_ATTACKDOWN	16
#define STATE_ATTACKLEFT	17

#define STATE_DYING			0

class cBicho
{
public:
	cBicho(void);
	virtual ~cBicho(void);

	void SetPosition(int x,int y);
	void SetX(int x);
	int  GetX();
	void SetY(int y);
	int  GetY();
	void SetBaseTilesHeight(int bth);
	int  GetBaseHeight();
	void SetBaseTilesWidth(int btw);
	int  GetBaseWidth();
	void SetHitHeight(int hh);
	int GetHitHeight();
	void SetHitWidth(int hw);
	int GetHitWidth();


	std::vector<int> GetTiles(); //	returns the positions of the tiles with which the base of the bug intersects
	cRect GetHitBox();
	bool Intersection(cRect box1, cRect box2);
	bool Intersection(cRect box1,int px,int py);
	void SetTile(int tx,int ty);

	virtual void Draw(int tex_id,int tex_w,int tex_h,bool run) {}; //when we call a virtual function the function of the same name of the corresponding subclass will be executed

	void Stop();

	void StartAttack();

	void SetState(int s);
	int  GetState();

	void SetFrame(int frame);
	int  GetFrame();

	void SetDelay(int d);
	int  GetDelay();

	bool IsLooking();
	bool IsWalking();
	bool IsAttacking();
	bool IsDamaged();
	
	void SetMaxHealth(int max_h);
	int  GetMaxHealth();
	void SetHealth(int health);
	int  GetHealth();
	void SetDamage(int damage);
	int  GetDamage();
	
private:
	int x,y, //the lower left pixel of the bug hitbox
		hit_w,hit_h, //dimensions in pixels of the hittable part of a frame of the sprite, it is not necessary that they be divisible by TILE_SIZE, but in the associated sprites the hitbox must be in the center / center of each frame
		base_tiles_w, base_tiles_h, //tile dimensions of collidable base
		state,
		seq,delay, //seq is the frame of the animation sequence that has to be painted now, delay is waiting for one of those frames to another
		max_health,health,damage;
};
