#include "common.h"
#include "map.h"

extern s32 D_8009A5D0;
extern s32 D_8009A678;

s32 get_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    return currentEncounter->defeatFlags[mapID][encounterIdx] & (1 << encounterShift);
}

void set_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift;
    s32 flag;

    flag = encounterID % 32;
    encounterShift = flag;
    flag = currentEncounter->defeatFlags[mapID][encounterIdx];
    currentEncounter->defeatFlags[mapID][encounterIdx] = flag | (1 << encounterShift);

    // TODO: The below should work but has regalloc issues:
    /*EncounterStatus *currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    currentEncounter->defeatFlags[mapID][encounterIdx] |= (1 << encounterShift);*/
}

ApiStatus func_8003EE98(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_80045D00(0, 60);
    }
    return (func_80045FA4() == 0) * ApiStatus_DONE2;
}

ApiStatus func_8003EECC(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_80045D00(1, 60);
    }
    return (func_80045FA4() == 0) * ApiStatus_DONE2;
}

ApiStatus FadeBackgroundToBlack(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_8011D82C(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, ((25 - script->functionTemp[0].s) * 10) & 254);
    script->functionTemp[0].s--;
    do {} while (0);
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}

ApiStatus UnfadeBackgroundFromBlack(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 10) & 0xFE);
    script->functionTemp[0].s -= 5;

    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_8003F018(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(-0xA);

    if (isInitialCall) {
        play_sound(0x24B);
        npc->unk_AC = 0;
    }

    npc->unk_AC += 17;

    if ((u32)(npc->unk_AC & 0xFF) >= 0xFF) {
        npc->unk_AC = 0xFF;
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8003F084(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(-0xA);

    npc->unk_AC -= 17;
    if (npc->unk_AC == 0) {
        npc->unk_AC = 0;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_8003F0C4);

ApiStatus func_8003F384(ScriptInstance* script, s32 isInitialCall) {
    D_800A0BB8 = 1;
    return ApiStatus_DONE2;
}

ApiStatus GetCamLookAtObjVector(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = CURRENT_CAM->lookAt_obj.x;
    script->varTable[1] = CURRENT_CAM->lookAt_obj.y;
    script->varTable[2] = CURRENT_CAM->lookAt_obj.z;

    return ApiStatus_DONE2;
}

ApiStatus HasMerleeCasts(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if (gPlayerData.merleeCastsLeft > 0) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_8003F414(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_800720B0(6, var0, var1, var2, 1.2f, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_8003F4CC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_80071750(9, var0, var1, var2, 5.0f, 15);
    return ApiStatus_DONE2;
}

ApiStatus OnDefeatEnemy(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp1;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 20;
    }

    if (script->functionTemp[1].s & 1) {
        npc->flags &= ~2;
    } else {
        npc->flags |= 2;
    }

    if (script->functionTemp[1].s == 15) {
        play_sound(SoundId_DEATH);
        func_80070190(1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0, -1.0f, 0, 10);
    }

    temp1 = script->functionTemp[1].s;
    if (script->functionTemp[1].s == 10) {
        func_8006F8F0(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        if (script->functionTemp[1].s == temp1) { // what? (never can be false, seemingly)
            spawn_drops(enemy);
        }
    }

    script->functionTemp[1].s -= 1;

    if (script->functionTemp[1].s == 0) {
        npc->flags |= 2;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus OnFleeBattleDrops(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 40;
        script->functionTemp[2].s = 0;
    }

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= 5) {
        if (rand_int(100) < 50) {
            if (playerData->coins != 0) {
                playerData->coins--;
                make_item_entity_delayed(ItemId_COIN, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight,
                                         playerStatus->position.z, 3, 0, 0);
            }
        }
        script->functionTemp[2].s = 0;
    }

    return --script->functionTemp[1].s == 0;
}

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_8003F7CC);

void func_8004135C() {
}

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_80041364);

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_80041964);

INCLUDE_ASM(s32, "code_1a1f0_len_5390", show_first_strike_message);

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_80041F10);

s32 func_8004304C(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 ret = currentEncounter->unk_98;

    if (ret != 0) {
        func_80137D88(0, currentEncounter->unk_90);
        ret = func_80137E10(0, 0, 0, 0);
    }

    return ret;
}

void func_8004309C(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = PLAYER_STATUS;
    Enemy* currentEnemy;
    s32 flag;

    switch (D_8009A5D0) {
        case 0:
            currentEnemy = encounter->currentEnemy;
            flag = FALSE;

            if (currentEnemy->interactScript != NULL) {
                if (does_script_exist(currentEnemy->interactScriptID)) {
                    flag = TRUE;
                } else {
                    currentEnemy->interactScript = NULL;
                }
            }

            if (currentEnemy->hitScript != NULL) {
                if (does_script_exist(currentEnemy->hitScriptID)) {
                    flag = TRUE;
                } else {
                    currentEnemy->hitScript = NULL;
                }
            }

            if (!flag) {
                D_8009A5D0 = 1;
            }
            break;
        case 1:
            resume_all_group(1);

            currentEnemy = encounter->currentEnemy;
            if (currentEnemy != NULL && currentEnemy->aiScript != NULL) {
                resume_all_script(currentEnemy->aiScriptID);
            }

            enable_player_input();
            func_800EF600();

            if (playerStatus->actionState == ActionState_CONVERSATION) {
                set_action_state(ActionState_IDLE);
            }

            func_800EF3D4(0);
            encounter->hitType = 0;
            resume_all_group(16);
            gGameState = 2;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
    }
}

void func_800431D4() {
}

INCLUDE_ASM(s32, "code_1a1f0_len_5390", func_800431DC);

INCLUDE_ASM(s32, "code_1a1f0_len_5390", create_npcs);

void func_80044140() {
}

s32 func_80044148(void) {
    s32 ret = gGameState == 3;

    if (gCurrentEncounter.hitType == 5) {
        ret = 1;
    }
    return ret;
}
