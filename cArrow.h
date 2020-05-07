#pragma once

#include "cProjectile.h"

class cArrow: public cProjectile
{
public:
	cArrow();
	~cArrow();

	void Draw(int tex_id,int tex_w,int tex_h,bool run); //this actually summons the texture by id....... and draws it into the world. height and width are determined by ints. has a boolean what i can only assume does boolean things..
};