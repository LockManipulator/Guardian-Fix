#include "main.h"
#include "cwmods/cwsdk.h"
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <windows.h>

class Mod : GenericMod {
	virtual void OnCreatureHPCalculated(cube::Creature* creature, float* hp) {
		if (creature->entity_data.classType == 1 && creature->entity_data.specialization == 1) {
			float guardianHp = (*hp - 25.0f) * 1.25f;
			*hp = guardianHp > 125.0f ? guardianHp : 125.0f;
		}
	}

};

EXPORT Mod* MakeMod() {
	return new Mod();
}