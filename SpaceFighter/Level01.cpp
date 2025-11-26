

#include "Level01.h"
#include "BioEnemyShip.h"
#include "LargeShip.h"


void Level01::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture *pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");
	Texture *pLargeTexture = resourceManager.Load<Texture>("Textures\\LargeEnemy.png");

	const int COUNT = 21;
	int largeShipCount = 0;
	const int maxLargeShips = 3;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};
	
	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;


	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip *pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);


		if (i == 5 || i == 12 || i == 18)
		{
			LargeShip* pLarge = new LargeShip();
			pLarge->SetTexture(pLargeTexture);
			pLarge->SetCurrentLevel(this);
			pLarge->Initialize(position, (float)delay);
			AddGameObject(pLarge);
		}
	}

	


	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground01.png"));

	Level::LoadContent(resourceManager);
}

