
#pragma once

#include "EnemyShip.h"

class LargeShip : public EnemyShip
{

public:

	LargeShip();
	virtual ~LargeShip() {}

	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime& gameTime);

	virtual void Draw(SpriteBatch& spriteBatch);


private:

	Texture* m_pTexture = nullptr;

	float m_spawnTimer = 0;
	bool m_hasSpawnDelay = false;

};