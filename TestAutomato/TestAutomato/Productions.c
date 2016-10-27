//
//  Productions.c
//  TestAutomato
//
//  Created by Rodrigo Soldi Lopes on 26/10/16.
//  Copyright © 2016 Rodrigo Soldi. All rights reserved.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>
#include "HardProductions.c"


// Functions ===========
static void createProductions();


// Global Variables =========
static Production *productions[];


// Implementations =========
static void createProductions() {
    productions[0] = createPROG1();
    productions[1] = createPROG2();
    productions[2] = createCLASSE_X1();
    productions[3] = createCLASSE_X2();
    productions[4] = createMAIN();
    productions[5] = createCLASSE1();
    productions[6] = createCLASSE2();
    productions[7] = createMETODO_X1();
    productions[8] = createMETODO_X2();
    productions[9] = createCLASSE3();
    productions[10] = createVAR_X1();
    productions[11] = createVAR_X2();
    productions[12] = createCLASSE4();
    productions[13] = createVAR_METODO_X1();
    productions[14] = createVAR_METODO_X2();
    productions[15] = createVAR1();
    productions[16] = createMETODO1();
    productions[17] = createMETODO2();
    productions[18] = createVAR_CMD_X1();
    productions[19] = createCMD_X1();
    productions[20] = createCMD_X2();
    productions[21] = createVAR_CMD_X2();
    productions[22] = createVAR_CMD_X3();
    productions[23] = createVAR_CMD_X4();
    productions[24] = createMETODO3();
    productions[25] = createMETODO4();
    productions[26] = createPARAMS1();
    productions[27] = createPARAMS2();
    productions[28] = createTIPOS_X1();
    productions[29] = createTIPOS_X2();
    productions[30] = createTIPO1();
    productions[31] = createTIPO2();
    productions[32] = createTIPO3();
    productions[33] = createTIPO4();
    productions[34] = createCMD1();
    productions[35] = createCMD2();
    productions[36] = createCMD3();
    productions[37] = createCMD4();
    productions[38] = createCMD5();
    productions[39] = createCMD6();
    productions[40] = createEXP1();
    productions[41] = createEXP2();
    productions[42] = createREXP1();
    productions[43] = createREXP2();
    productions[44] = createREXP3();
    productions[45] = createREXP4();
    productions[46] = createAEXP1();
    productions[47] = createAEXP2();
    productions[48] = createAEXP3();
    productions[49] = createMEXP1();
    productions[50] = createMEXP2();
    productions[51] = createSEXP1();
    productions[52] = createSEXP2();
    productions[53] = createSEXP3();
    productions[54] = createSEXP4();
    productions[55] = createSEXP5();
    productions[56] = createSEXP6();
    productions[57] = createSEXP7();
    productions[58] = createSEXP8();
    productions[59] = createPEXP1();
    productions[60] = createPEXP2();
    productions[61] = createPEXP3();
    productions[62] = createPEXP4();
    productions[63] = createPEXP5();
    productions[64] = createPEXP6();
    productions[65] = createPEXP7();
    productions[66] = createEXPS1();
    productions[67] = createEXPS2();
    productions[68] = createEXP_X1();
    productions[69] = createEXP_X2();
}

