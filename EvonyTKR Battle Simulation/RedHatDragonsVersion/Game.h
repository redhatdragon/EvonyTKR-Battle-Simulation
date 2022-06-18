#pragma once

#include <stdint.h>

#define TROOP_TIER_MAX 15
#define TROOP_TYPE_MAX 4

struct TROOP_TYPE {
	enum TYPES {
		GROUND,
		RANGED,
		CAV,
		SIEGE
	};
};

struct Buff {

};

struct TroopData {
	uint32_t count;
	uint32_t pos;
};  //8 bytes == 8 per cacheline

struct Field {
	TroopData _troopData[TROOP_TYPE_MAX][TROOP_TIER_MAX][2];  //960 bytes == 15 cacheline reads

	inline bool troopExists(uint32_t type, uint32_t tier, uint8_t side) {
		return _troopData[type][tier][side].count;
	}
	inline uint32_t getTroopCount(uint32_t type, uint32_t tier, uint8_t side) {
		return _troopData[type][tier][side].count;
	}
	inline TroopData* getTroopDataPtr(uint32_t type, uint32_t tier, uint8_t side) {
		return &_troopData[type][tier][side];
	}
};

//If these prove inaccurate in some situations, i'll have to create a filter function with a blacklist...  slow runtimes yaaaay~
TROOP_TYPE::TYPES fastestTroopToSlowest[TROOP_TIER_MAX] = 
	{ TROOP_TYPE::CAV, TROOP_TYPE::RANGED, TROOP_TYPE::GROUND, TROOP_TYPE::SIEGE };
TROOP_TYPE::TYPES fastestTroopToSlowestNonMeleeFirst[TROOP_TIER_MAX] =
{ TROOP_TYPE::RANGED, TROOP_TYPE::SIEGE, TROOP_TYPE::GROUND, TROOP_TYPE::CAV };

class Game {
	Field field;

	void move() {

	}
	void attack() {

	}
	void removeLosses() {

	}
public:
	void tick() {
		move();
		attack();
		removeLosses();
	}
};