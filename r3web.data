|SCR 512 512
|MEM 4095
#w5E 0
:w5F 0 'w5E ! ( w5E 0? DROP UPDATE DUP EX REDRAW ) 2DROP 0 'w5E ! ;
:w60 1 'w5E ! ;
:w6A >R DUP $ff00ff AND PICK2 $ff00ff AND OVER - R@ * 8 >> + $ff00ff AND ROT ROT $ff00 AND SWAP $ff00 AND OVER - R> * 8 >> + $ff00 AND OR ;
:w6B VFRAME >A SH ( 1? 1 - SW ( 1? 1 - 2DUP XOR MSEC 2 >> + $ff AND $ff0000 $ff ROT w6A A!+ ) DROP ) DROP KEY 27 =? ( w60 ) DROP ;
: 'w6B w5F ;

