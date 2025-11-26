
#include "LargeShip.h"
#include "Level.h"


LargeShip::LargeShip()
{
	SetSpeed(50);
	SetMaxHitPoints(5);
	SetCollisionRadius(20);
}


void LargeShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = 0;
		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		if (!IsOnScreen())
		{
			Deactivate();
			std::cout << "A Large ship has been deactivated" << "\n";
		}

	}
	EnemyShip::Update(gameTime);
}


void LargeShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
