.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069368
/* 44768 80069368 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 4476C 8006936C AFB00078 */  sw        $s0, 0x78($sp)
/* 44770 80069370 00808021 */  addu      $s0, $a0, $zero
/* 44774 80069374 00002821 */  addu      $a1, $zero, $zero
/* 44778 80069378 AFBF0080 */  sw        $ra, 0x80($sp)
/* 4477C 8006937C 0C01A5AC */  jal       func_800696B0
/* 44780 80069380 AFB1007C */   sw       $s1, 0x7c($sp)
/* 44784 80069384 14400026 */  bnez      $v0, .L80069420
/* 44788 80069388 00003021 */   addu     $a2, $zero, $zero
/* 4478C 8006938C 8E040004 */  lw        $a0, 4($s0)
/* 44790 80069390 8E050008 */  lw        $a1, 8($s0)
/* 44794 80069394 0C01A86C */  jal       func_8006A1B0
/* 44798 80069398 27A70058 */   addiu    $a3, $sp, 0x58
/* 4479C 8006939C 14400020 */  bnez      $v0, .L80069420
/* 447A0 800693A0 27A30037 */   addiu    $v1, $sp, 0x37
/* 447A4 800693A4 2402001F */  addiu     $v0, $zero, 0x1f
.L800693A8:
/* 447A8 800693A8 A0620000 */  sb        $v0, ($v1)
/* 447AC 800693AC 2442FFFF */  addiu     $v0, $v0, -1
/* 447B0 800693B0 0441FFFD */  bgez      $v0, .L800693A8
/* 447B4 800693B4 2463FFFF */   addiu    $v1, $v1, -1
/* 447B8 800693B8 AFA00010 */  sw        $zero, 0x10($sp)
/* 447BC 800693BC 8E040004 */  lw        $a0, 4($s0)
/* 447C0 800693C0 8E050008 */  lw        $a1, 8($s0)
/* 447C4 800693C4 00003021 */  addu      $a2, $zero, $zero
/* 447C8 800693C8 0C01A8E8 */  jal       func_8006A3A0
/* 447CC 800693CC 27A70018 */   addiu    $a3, $sp, 0x18
/* 447D0 800693D0 14400013 */  bnez      $v0, .L80069420
/* 447D4 800693D4 00003021 */   addu     $a2, $zero, $zero
/* 447D8 800693D8 8E040004 */  lw        $a0, 4($s0)
/* 447DC 800693DC 8E050008 */  lw        $a1, 8($s0)
/* 447E0 800693E0 27B10038 */  addiu     $s1, $sp, 0x38
/* 447E4 800693E4 0C01A86C */  jal       func_8006A1B0
/* 447E8 800693E8 02203821 */   addu     $a3, $s1, $zero
/* 447EC 800693EC 1440000C */  bnez      $v0, .L80069420
/* 447F0 800693F0 27A40018 */   addiu    $a0, $sp, 0x18
/* 447F4 800693F4 02202821 */  addu      $a1, $s1, $zero
/* 447F8 800693F8 0C01AE14 */  jal       func_8006B850
/* 447FC 800693FC 24060020 */   addiu    $a2, $zero, 0x20
/* 44800 80069400 14400007 */  bnez      $v0, .L80069420
/* 44804 80069404 2402000B */   addiu    $v0, $zero, 0xb
/* 44808 80069408 AFA00010 */  sw        $zero, 0x10($sp)
/* 4480C 8006940C 8E040004 */  lw        $a0, 4($s0)
/* 44810 80069410 8E050008 */  lw        $a1, 8($s0)
/* 44814 80069414 00003021 */  addu      $a2, $zero, $zero
/* 44818 80069418 0C01A8E8 */  jal       func_8006A3A0
/* 4481C 8006941C 27A70058 */   addiu    $a3, $sp, 0x58
.L80069420:
/* 44820 80069420 8FBF0080 */  lw        $ra, 0x80($sp)
/* 44824 80069424 8FB1007C */  lw        $s1, 0x7c($sp)
/* 44828 80069428 8FB00078 */  lw        $s0, 0x78($sp)
/* 4482C 8006942C 03E00008 */  jr        $ra
/* 44830 80069430 27BD0088 */   addiu    $sp, $sp, 0x88
/* 44834 80069434 00000000 */  nop
/* 44838 80069438 00000000 */  nop
/* 4483C 8006943C 00000000 */  nop