//-----------------------------------------------------------------------------
// File: CPlayer.cpp
//
// Desc: This file stores the player object class. This class performs tasks
//	   such as player movement, some minor physics as well as rendering.
//
// Original design by Adam Hoult & Gary Simmons. Modified by Mihai Popescu.
//-----------------------------------------------------------------------------

#ifndef _CPLAYER_H_
#define _CPLAYER_H_

//-----------------------------------------------------------------------------
// CPlayer Specific Includes
//-----------------------------------------------------------------------------
#include "Main.h"
#include "Vec2.h"
#include "Sprite.h"
#include"windows.h"
#include <algorithm>
//-----------------------------------------------------------------------------
// Main Class Definitions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Name : CPlayer (Class)
// Desc : Player class handles all player manipulation, update and management.
//-----------------------------------------------------------------------------
class CPlayer
{
public:
	//-------------------------------------------------------------------------
	// Enumerators
	//-------------------------------------------------------------------------
	enum DIRECTION 
	{ 
		DIR_FORWARD	 = 1, 
		DIR_BACKWARD	= 2, 
		DIR_LEFT		= 4, 
		DIR_RIGHT	   = 8, 
	};

	enum ESpeedStates
	{
		SPEED_START,
		SPEED_STOP
	};
	
	//-------------------------------------------------------------------------
	// Constructors & Destructors for This Class.
	//-------------------------------------------------------------------------
			 CPlayer(const BackBuffer *pBackBuffer);
	virtual ~CPlayer();

	//-------------------------------------------------------------------------
	// Public Functions for This Class.
	//-------------------------------------------------------------------------
	void					Update( float dt );
	void					Draw();
	void					Move(ULONG ulDirection);
	void					Fire();
	void					EnemyFire();
	Vec2&					Position();
	Vec2&					qPosition();
	Vec2&					Velocity();
	bool EnemyHit = false;
	bool PlayerHit = false;
	bool left;
	int count = 0;
	void					Explode();
	bool					AdvanceExplosion();
	void					QExplode();
	bool					QAdvanceExplosion();

	bool					AdvanceFire();

	Vec2 *gBulletList;
private:
	//-------------------------------------------------------------------------
	// Private Variables for This Class.
	//-------------------------------------------------------------------------
	Sprite*					m_pSprite;
	Sprite*					q_pSprite;
	ESpeedStates			m_eSpeedState;
	float					m_fTimer;
	
	bool					m_bExplosion;
	AnimatedSprite*			m_pExplosionSprite;
	int						m_iExplosionFrame;

	bool					q_bExplosion;
	AnimatedSprite*			q_pExplosionSprite;
	int						q_iExplosionFrame;


	AnimatedSprite*	 m_pFireSprite;
	bool m_bFire ;

	AnimatedSprite*	 m_pEnemyFireSprite;
	bool m_bEnemyFire;
};

#endif // _CPLAYER_H_