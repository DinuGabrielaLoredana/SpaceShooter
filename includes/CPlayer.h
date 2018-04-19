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
#include"BackBuffer.h"
#include "Vec2.h"
#include "Sprite.h"
#include"windows.h"
#include <algorithm>
#include <math.h>

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
		DIR_W = 2,
		DIR_A = 1,
		DIR_S = 4,
		DIR_D = 8,
		
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
	void					MoveEnemy(ULONG ulDirection);
	void					Fire();
	void					EnemyFire();
	Vec2&					Position();
	Vec2&					enemyPosition();
	Vec2&					Velocity();
	Vec2 gGunDir;
	BackBuffer*				sm_pBBuffer;
	
	AnimatedSprite*	 m_pPlayerLivesSprite;
	int						m_iPlayerLifeFrame = 0;

	AnimatedSprite*	 m_pEnemyLivesSprite;
	int						m_iEnemyLifeFrame = 0;
	int lives;
	int points;
	int rotationDirection;
	int enemyRotation;
	bool EnemyHit = false;
	bool PlayerHit = false;
	bool col = false;
	bool left;
	int count = 0;
	bool  d = 0; bool l = 0;bool  r = 0;
	bool  d1 = 0; bool l1 = 0; bool  r1 = 0; bool u1 = 0;
	bool u = 0;
	bool gameOver = 0;
	void					Explode();
	bool					AdvanceExplosion();
	void					QExplode();
	bool					QAdvanceExplosion();

	bool					AdvanceFire();
	void CollisionDetection();
	Vec2 *gBulletList;
	Sprite*					m_pSprite;
	Sprite*					gameOver1;
	Sprite*					gameOver2;
	Sprite*					aux;
	Sprite*					aux1;
	Sprite*					q_pSprite;
	AnimatedSprite*	 m_pFireSprite;
	AnimatedSprite*	 m_pEnemyFireSprite;
private:
	//-------------------------------------------------------------------------
	// Private Variables for This Class.
	//-------------------------------------------------------------------------
	
	
	
	ESpeedStates			m_eSpeedState;
	float					m_fTimer;
	
	bool					m_bExplosion;
	AnimatedSprite*			m_pExplosionSprite;
	int						m_iExplosionFrame;

	bool					q_bExplosion;
	AnimatedSprite*			q_pExplosionSprite;
	int						q_iExplosionFrame;



	bool m_bFire ;

	
	bool m_bEnemyFire;

	
};

#endif // _CPLAYER_H_
