#include "common.h"

INCLUDE_ASM(s32, "battle/move/spin_smash_737890", func_802A1000_737890);

INCLUDE_ASM(s32, "battle/move/spin_smash_737890", func_802A1074_737904);

INCLUDE_ASM(s32, "battle/move/spin_smash_737890", func_802A10EC_73797C);
ApiStatus func_802A10EC_73797C(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(&gBattleStatus.unk_83);
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER) != FALSE) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A113C_7379CC(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON) != FALSE) {
        script->varTable[0] = 1;
    }

    if ((gBattleStatus.flags1 & 0x1000) != FALSE) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
