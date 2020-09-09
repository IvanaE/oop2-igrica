#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#include "sprite.h"
#include "level.h"
#include "poklon.h"
#include "protivnik.h"
#include "dedamraz.h"



/** detektuje koliziju i je li dm donio
 */
class Group
 {
public:
    Group();
    int scor = 0;
    int kolizijasaPoklonom(Dedamraz *sprite, Poklon *poklon); // kad se dm susretne sa poklonom
    void kolizijaMonstrumDeda(Dedamraz *sprite, Protivnik *protivnik);
    void kolizijaMonstrumPoklon(Protivnik *protivnik, Poklon *poklon);

};


#endif // GROUP_H

