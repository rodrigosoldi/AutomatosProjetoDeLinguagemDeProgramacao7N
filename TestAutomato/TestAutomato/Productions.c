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
    productions[0] = createPROG();
}

