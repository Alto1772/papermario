#include "audio.h"

void func_80052E30(u8 index) {
    UnkAl48* temp = &D_8009A5C0->unk_1320[index];

    temp->unk_1C = 0;
    temp->unk_45 = 0;
}

void func_80052E5C(s32 arg0) {
    UnkAl19E0** temp_s4 = &D_8009A5C0;
    UnkAl19E0* temp4;
    s32* temp_v0_2;
    ALHeap* alHeap;
    u32 i;
    s32 subroutine_arg7[2];
    u8 temp6[4];
    UnkAlA9C** temp1 = &D_8009A664;
    UnkAlA9C** temp1_1;
    UnkAl6CC** temp2 = &D_8009A640;
    UnkAl6CC** temp2_1;
    UnkAlA9C** temp3;
    UnkAl48* temp5;
    u8* temp7;
    s32** temp8;

    alHeap = D_80078E54->unk_18;
    *temp_s4 = alHeapAlloc(alHeap, 1, 0x19E0);

    (*temp1) = alHeapAlloc(alHeap, 1, 0xA9C);
    D_8009A5FC = alHeapAlloc(alHeap, 1, 0xA9C);
    D_8009A5CC = alHeapAlloc(alHeap, 1, 0xA9C);
    (*temp2) = alHeapAlloc(alHeap, 1, 0x6CC);
    D_8009A628 = alHeapAlloc(alHeap, 1, 0x834);
    (*temp1)->unk_04 = (*temp2);
    D_8009A628->unk_00 = *(temp_s4);


    temp4 = *temp_s4;
    temp_v0_2 = alHeapAlloc(alHeap, 1, 0x8000);
    temp4->unk_5C = &temp_v0_2[0];
    temp4->unk_60 = &temp_v0_2[0x1400];
    temp4->unk_64 = &temp_v0_2[0x1C00];
    temp4->unk_68 = &temp_v0_2[0x1400];

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_0 = alHeapAlloc(alHeap, 1, 0xA9C);
    }

    temp4->unk_A0 = alHeapAlloc(alHeap, 1, 0x5200);
    temp4->unk_04 = alHeapAlloc(alHeap, 1, 0x30);
    temp4->unk_54 = alHeapAlloc(alHeap, 1, 0x360);
    temp4->unk_58 = alHeapAlloc(alHeap, 1, 0x200);
    temp4->unk_94 = alHeapAlloc(alHeap, 1, 0x40);
    temp4->unk_00 = arg0;
    func_800532F4(temp4->unk_04);
    func_80053370(&temp4->unk_08);
    func_800533A8(&temp4->unk_14);
    func_8005610C();
    temp4->unk_A4 = 0;
    temp4->unk_A8 = 0;

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_4 = 0;
        temp4->unk_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        temp4->unk_40[i].unk_00 = 0;
        temp4->unk_40[i].unk_01 = 0;
    }

    for (i = 0; i < 24; i++) {
        func_80056EC0((u8)i, 0);
        func_80057224((u8)i, temp4->unk_04);
        temp5 = &temp4->unk_1320[i];
        temp5->unk_00 = 0;
        temp5->unk_04 = 0;
        temp5->unk_0C = -1;
        temp5->unk_0E = 0xFF;
        temp5->unk_0F = 0xFF;
        temp5->unk_10 = 0;
        temp5->unk_42 = 0;
        temp5->unk_43 = 0;
        temp5->unk_44 = 0;
        temp5->unk_45 = 0;
    }

    al_LoadINIT(temp4, 0xF00000, alHeap);

    for (i = 0; i < 3; i++) {
        temp4->unk_1310[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    temp2_1 = &D_8009A640;
    temp3 = &D_8009A5FC;
    temp1_1 = &D_8009A664;
    func_8004E158((*temp1_1), 1, 0, temp4);
    temp6[0] = 0;
    temp6[1] = 3;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    temp7 = &temp6[0];
    func_8004E344((*temp1_1), temp7);
    func_8004E158((*temp3), 2, 2, temp4);
    temp6[0] = 2;
    temp6[1] = 0xff;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344((*temp3), temp7);
    func_8004B440((*temp2_1), 4, 1, temp4, 0x10);
    func_80050B90(D_8009A628, 6, 1, temp4);
    func_80052614(temp4);
    al_LoadBKHeaders(temp4, alHeap);
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_0, 0x20, &subroutine_arg7) == 0) {
        al_DmaCopy(subroutine_arg7[0], temp4->unk_A0, subroutine_arg7[1] & 0xFFFFFF);
    }
    func_8004B62C((*temp2_1));
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_2, 0x40, subroutine_arg7) == 0) {
        al_LoadPER(temp4, subroutine_arg7[0]);
    }
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_4, 0x40, &subroutine_arg7) == 0) {
        al_LoadPRG(temp4, subroutine_arg7[0]);
    }

    temp4->unk_12EC = &temp4->unk_4EC;
    temp4->unk_12F0 = &temp4->unk_5EC;
    temp4->unk_12F4 = &temp4->unk_AC;
    temp4->unk_12F8 = &temp4->unk_EC;
    temp4->unk_12FC = &temp4->unk_9EC;
    temp4->unk_1300 = &temp4->unk_DEC;
    temp4->unk_1304 = &temp4->unk_11EC;
    temp4->unk_1308 = &temp4->unk_4EC;
    temp4->unk_53 = 0;
    temp4->unk_52 = 0;
    temp4->unk_51 = 0;
    temp4->unk_50 = 0;

    func_80057ED0(0);
    func_80055050(alHeap);
}

void func_800532F4(UnkAl30* arg0) {
    arg0->unk_00 = &D_800781D0;
    arg0->unk_04 = 190;
    arg0->unk_18 = &D_80078190;
    arg0->unk_1C = 64;
    arg0->unk_1E = 4800;
    arg0->unk_08 = 0;
    arg0->unk_0C = 0;
    arg0->unk_10 = 0;
    arg0->unk_14 = 0;
    arg0->unk_24 = 0;
    arg0->unk_25 = 0;
    arg0->unk_2C = &D_80078544;
    arg0->unk_26 = 0;
    arg0->unk_27 = 0;
    arg0->unk_28 = 0;
    arg0->unk_29 = 0;
    arg0->unk_2A = 0;
    arg0->unk_2B = 0;
    arg0->unk_20 = 0.5f;
}

void func_80053370(UnkAl12* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = 4800;
    arg0->unk_04 = ~0x80;
    arg0->unk_05 = 64;
    arg0->unk_06 = 0;
    arg0->unk_07 = 0;
    arg0->unk_08 = 0;
    arg0->unk_09 = 0;
    arg0->unk_0A = 0;
}

void func_800533A8(alUnk2* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = ~0x80;
    arg0->unk_03 = 64;
    arg0->unk_04 = 0;
    arg0->unk_05 = 0;
    arg0->unk_06 = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800533D0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800535C0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053654);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053888);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800538C4);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800538F8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053974);

void func_80053A18(UnkStructFor80053A18* arg0) {
    arg0->unk_0A = 0;
    arg0->unk_04 = 0;
    arg0->unk_0C = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053A28);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053A98);

void func_80053AC8(alUnk1* arg0) {
    if (arg0->unk_0A == 0) {
        arg0->unk_0A = 1;
        arg0->unk_04 = 0;
        arg0->unk_08 = arg0->unk_00;
    }
}

void func_80053AEC(alUnk1* arg0, s16 arg1) {
    arg0->unk_10 = arg1 << 16;
    arg0->unk_18 = arg1;
    arg0->unk_1A = 0;
    arg0->unk_14 = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053B04);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053BA8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053BE8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053C58);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053CB4);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053CF8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053E58);

UnkAlA9C* func_80053F64(s32 arg0) {
    if (arg0 == 0) {
        return D_8009A5C0->unk_6C[0].unk_0; // 0x6C
    }
    return 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053F80);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054248);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadINIT, UnkAl19E0* arg0, s32 arg1, ALHeap* arg2);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_CopyFileTableEntry, u16 arg0, s32 arg1, s32* arg2);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadPER, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadPRG, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_8005465C);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054744);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_LoadBank);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800549F8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054AA0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054C4C);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054C84);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054CE0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054D74);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054DA8);

INCLUDE_ASM(void, "code_2e230_len_2190", al_DmaCopy, s32* arg0, s32* arg1, s32 arg2);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054E90);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054F48);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_CopyWords);
