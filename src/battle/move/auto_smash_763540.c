#include "common.h"

ApiStatus func_802A1000_763540(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(&gBattleStatus.unk_83);
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER) != FALSE) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

#ifdef NOT_MATCHING
ApiStatus func_802A1050_763590(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON) != FALSE) {
        script->varTable[0] = 1;
    }

    if ((gBattleStatus.flags1 & 0x1000) != FALSE) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/move/auto_smash_763540", func_802A1050_763590);
#endif
