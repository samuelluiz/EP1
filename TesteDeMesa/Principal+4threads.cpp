#include <iostream>
#include <random>
#include <thread>
#include <Windows.h>
int n;
int matA[200][200];
int matB[200][200];
int matC[200][200];
using namespace std;

//MATRIZ A
void geraMatrizA(){
    default_random_engine gerador;
    uniform_int_distribution <int> distribuicao(1,10);

    int l, c;
    n = 200;
    for(l=0; l<n; l++){
    for(c=0; c<n; c++){
        matA[l][c] = distribuicao(gerador);
    }
}
}

//MATRIZ B
void geraMatrizB(){
    default_random_engine gerador;
    uniform_int_distribution <int> distribuicao(1,10);

    int l, c;
    n = 200;
    for(l=0; l<n; l++){
    for(c=0; c<n; c++){
        matB[l][c] = distribuicao(gerador);
    }
}
}

// SEQUENCIAL --------------------------------------------------------------------------------------------------------------
double geraMatrizC_12(){
    __int64 freq,start,stop;
double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux=0;
    for(l=0; l<12; l++){
    for(c=0; c<12; c++){
            matC[l][c]=0;
            for(x=0; x<12; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

double geraMatrizC_20(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<20; l++){
    for(c=0; c<20; c++){
            matC[l][c]=0;
            for(x=0; x<20; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

double geraMatrizC_40(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux =0;
    for(l=0; l<40; l++){
    for(c=0; c<40; c++){
            matC[l][c]=0;
            for(x=0; x<40; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

double geraMatrizC_80(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<80; l++){
    for(c=0; c<80; c++){
            matC[l][c]=0;
            for(x=0; x<80; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

double geraMatrizC_100(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<100; l++){
    for(c=0; c<100; c++){
            matC[l][c]=0;
            for(x=0; x<100; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}


double geraMatrizC_120(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<120; l++){
    for(c=0; c<120; c++){
            matC[l][c]=0;
            for(x=0; x<120; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}


double geraMatrizC_160(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<160; l++){
    for(c=0; c<160; c++){
            matC[l][c]=0;
            for(x=0; x<160; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

double geraMatrizC_200(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux = 0;
    for(l=0; l<200; l++){
    for(c=0; c<200; c++){
            matC[l][c]=0;
            for(x=0; x<200; x ++){
                aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
}
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
tempo = ((double)stop-(double)start) / (double)freq;
return tempo;
}

//USANDO 2 THREADS ---------------------------------------------------------------------------------------------------------

double geraMatrizC_12_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 12;
    int l, c,x;
    thread t1_12_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_12_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_12_2t.join();
   t1_12_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;

}

double geraMatrizC_20_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 20;
    int l, c,x;
    thread t1_20_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_20_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_20_2t.join();
   t1_20_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_40_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 40;
    int l, c,x;
    thread t1_40_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_40_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_40_2t.join();
   t1_40_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_80_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 80;
    int l, c,x;
    thread t1_80_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_80_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_80_2t.join();
   t1_80_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_100_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 100;
    int l, c,x;
    thread t1_100_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_100_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_100_2t.join();
   t1_100_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_120_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 120;
    int l, c,x;
    thread t1_120_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_120_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_120_2t.join();
   t1_120_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_160_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 160;
    int l, c,x;
    thread t1_160_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_160_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_160_2t.join();
   t1_160_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_200_2t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 200;
    int l, c,x;
    thread t1_200_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_200_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_200_2t.join();
   t1_200_2t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

//USANDO 4 THREADS--------------------------------------------------------------------------------------------------------

double geraMatrizC_12_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 12;
    int l, c,x;
    thread t1_12_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_12_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_12_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_12_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_12_4t.join();
   t3_12_4t.join();
   t2_12_4t.join();
   t1_12_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_20_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 20;
    int l, c,x;
    thread t1_20_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_20_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_20_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_20_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_20_4t.join();
   t3_20_4t.join();
   t2_20_4t.join();
   t1_20_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_40_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 40;
    int l, c,x;
    thread t1_40_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_40_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_40_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_40_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_40_4t.join();
   t3_40_4t.join();
   t2_40_4t.join();
   t1_40_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

double geraMatrizC_80_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 80;
    int l, c,x;
    thread t1_80_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_80_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_80_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_80_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_80_4t.join();
   t3_80_4t.join();
   t2_80_4t.join();
   t1_80_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}


double geraMatrizC_100_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 100;
    int l, c,x;
    thread t1_100_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_100_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_100_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_100_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_100_4t.join();
   t3_100_4t.join();
   t2_100_4t.join();
   t1_100_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}


double geraMatrizC_120_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 120;
    int l, c,x;
    thread t1_120_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_120_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_120_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_120_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_120_4t.join();
   t3_120_4t.join();
   t2_120_4t.join();
   t1_120_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}


double geraMatrizC_160_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 160;
    int l, c,x;
    thread t1_160_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_160_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_160_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_160_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_160_4t.join();
   t3_160_4t.join();
   t2_160_4t.join();
   t1_160_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}


double geraMatrizC_200_4t(){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    n = 200;
    int l, c,x;
    thread t1_200_4t{[&](){
    for(l = 0; l < n/4; l++){
    for(c = 0; c < n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t2_200_4t{[&](){
    for(l = n/4; l < ((n/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t3_200_4t{[&](){
    for(l = n/4; l <  (((2*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};

    thread t4_200_4t{[&](){
    for(l = n/4; l < (((3*n)/4)+ 1) ; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t4_200_4t.join();
   t3_200_4t.join();
   t2_200_4t.join();
   t1_200_4t.join();

   QueryPerformanceCounter((LARGE_INTEGER *)&stop);

tempo = ((double)stop-(double)start) / (double)freq;

return tempo;
}

int main(){
int l, c;
double t12, t20, t40, t80, t100, t120, t160, t200;
double t12_2t, t20_2t, t40_2t, t80_2t, t100_2t, t120_2t, t160_2t, t200_2t;
double t12_4t, t20_4t, t40_4t, t80_4t, t100_4t, t120_4t, t160_4t, t200_4t;
double t12_nt, t20_nt, t40_nt, t80_nt, t100_nt, t120_nt, t160_nt, t200_nt;

geraMatrizA();
geraMatrizB();

//SEQUENCIAL-----------------------------------------------------------------------------------------------------------------
t12 = geraMatrizC_12();
t20 = geraMatrizC_20();
t40 = geraMatrizC_40();
t80 = geraMatrizC_80();
t100 = geraMatrizC_100();
t120 = geraMatrizC_120();
t160 = geraMatrizC_160();
t200 = geraMatrizC_200();

cout << "Matriz 12x12 de forma sequencial = " << t12 << endl;
cout << "Matriz 20x20 de forma sequencial = " << t20 << endl;
cout << "Matriz 40x40 de forma sequencial = " << t40 << endl;
cout << "Matriz 80x80 de forma sequencial = " << t80 << endl;
cout << "Matriz 100x100 de forma sequencial = " << t100 << endl;
cout << "Matriz 120x120 de forma sequencial = " << t120 << endl;
cout << "Matriz 160x160 de forma sequencial = " << t160 << endl;
cout << "Matriz 200x200 de forma sequencial = " << t200 << endl;

//2 THREADS-----------------------------------------------------------------------------------------------------------------
t12_2t = geraMatrizC_12_2t();
t20_2t = geraMatrizC_20_2t();
t40_2t = geraMatrizC_40_2t();
t80_2t = geraMatrizC_80_2t();
t100_2t = geraMatrizC_100_2t();
t120_2t = geraMatrizC_120_2t();
t160_2t = geraMatrizC_160_2t();
t200_2t = geraMatrizC_200_2t();

cout << "Matriz 12x12 usando 2 threads = " << t12_2t << endl;
cout << "Matriz 20x20 usando 2 threads = " << t20_2t << endl;
cout << "Matriz 40x40 usando 2 threads = " << t40_2t << endl;
cout << "Matriz 80x80 usando 2 threads = " << t80_2t << endl;
cout << "Matriz 100x100 usando 2 threads = " << t100_2t << endl;
cout << "Matriz 120x120 usando 2 threads = " << t120_2t << endl;
cout << "Matriz 160x160 usando 2 threads = " << t160_2t << endl;
cout << "Matriz 200x200 usando 2 threads = " << t200_2t << endl;

//4 THREADS---------------------------------------------------------------------------------------------------------------
t12_4t = geraMatrizC_12_4t();
t20_4t = geraMatrizC_20_4t();
t40_4t = geraMatrizC_40_4t();
t80_4t = geraMatrizC_80_4t();
t100_4t = geraMatrizC_100_4t();
t120_4t = geraMatrizC_120_4t();
t160_4t = geraMatrizC_160_4t();
t200_4t = geraMatrizC_200_4t();

cout << "Matriz 12x12 usando 4 threads = " << t12_4t << endl;
cout << "Matriz 20x20 usando 4 threads = " << t20_4t << endl;
cout << "Matriz 40x40 usando 4 threads = " << t40_4t << endl;
cout << "Matriz 80x80 usando 4 threads = " << t80_4t << endl;
cout << "Matriz 100x100 usando 4 threads = " << t100_4t << endl;
cout << "Matriz 120x120 usando 4 threads = " << t120_4t << endl;
cout << "Matriz 160x1600 usando 4 threads = " << t160_4t << endl;
cout << "Matriz 200x200 usando 4 threads = " << t200_4t << endl;

//PRINTS
for(int l=0; l <12; l++){
    for( c=0; c <12; c++){
        cout << "|"<< matA[l][c] << "|";
    }
    cout << endl;
}
cout<< endl;

for(int l=0; l <12; l++){
    for( c=0; c <12; c++){
        cout << "|"<< matB[l][c] << "|";
    }
    cout << endl;
}
cout<<endl;

for(int l=0; l <12; l++){
    for( c=0; c <12; c++){
        cout << "|"<< matC[l][c] << "|";
    }
    cout << endl;
}
return 0;
}
