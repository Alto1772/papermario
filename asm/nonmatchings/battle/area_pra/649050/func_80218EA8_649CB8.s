.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218EA8_649CB8
/* 649CB8 80218EA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 649CBC 80218EAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 649CC0 80218EB0 8C82000C */  lw        $v0, 0xc($a0)
/* 649CC4 80218EB4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 649CC8 80218EB8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 649CCC 80218EBC 0C0B2026 */  jal       set_variable
/* 649CD0 80218EC0 8C450000 */   lw       $a1, ($v0)
/* 649CD4 80218EC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 649CD8 80218EC8 24020002 */  addiu     $v0, $zero, 2
/* 649CDC 80218ECC 03E00008 */  jr        $ra
/* 649CE0 80218ED0 27BD0018 */   addiu    $sp, $sp, 0x18
