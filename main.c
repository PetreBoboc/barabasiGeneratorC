#include <stdio.h>
#include <stdlib.h>
#include "barabasi.h"

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    barabasi(n, m);

    system("display.bat");

}