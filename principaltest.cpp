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
double geraMatrizC(int n){
    __int64 freq,start,stop;
double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c, x, aux=0;
    for(l=0; l<n; l++){
    for(c=0; c<n; c++){
            matC[l][c]=0;
            for(x=0; x<n; x ++){
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

double geraMatrizC_2t(int n){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c,x;
    thread t1_2t{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_2t{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    t2_2t.join();
    t1_2t.join();
tempo = ((double)stop-(double)start) / (double)freq;

return tempo;

}


//USANDO 4 THREADS -------------------------------------------------------------------------------------------------------

double geraMatrizC_4t(int n){
    __int64 freq,start,stop;

double tempo;

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

QueryPerformanceCounter((LARGE_INTEGER *)&start);
    int l, c,x;
    thread t1_4t{[&](){
    for(l=0; l<n/4; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_4t{[&](){
    for(l=n/4; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t3_4t{[&](){
    for(l=n/2; l<((3*n)/4); l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t4_4t{[&](){
    for(l=((3*n)/4); l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    t1_4t.join();
    t2_4t.join();
    t3_4t.join();
    t4_4t.join();
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
t12 = geraMatrizC(12);
t20 = geraMatrizC(20);
t40 = geraMatrizC(40);
t80 = geraMatrizC(80);
t100 = geraMatrizC(100);
t120 = geraMatrizC(120);
t160 = geraMatrizC(160);
t200 = geraMatrizC(200);

cout << "Matriz 12x12 de forma sequencial = " << t12 << endl;
cout << "Matriz 20x20 de forma sequencial = " << t20 << endl;
cout << "Matriz 40x40 de forma sequencial = " << t40 << endl;
cout << "Matriz 80x80 de forma sequencial = " << t80 << endl;
cout << "Matriz 100x100 de forma sequencial = " << t100 << endl;
cout << "Matriz 120x120 de forma sequencial = " << t120 << endl;
cout << "Matriz 160x160 de forma sequencial = " << t160 << endl;
cout << "Matriz 200x200 de forma sequencial = " << t200 << endl;

//2 THREADS-----------------------------------------------------------------------------------------------------------------
t12_2t = geraMatrizC_2t(12);
t20_2t = geraMatrizC_2t(20);
t40_2t = geraMatrizC_2t(40);
t80_2t = geraMatrizC_2t(80);
t100_2t = geraMatrizC_2t(100);
t120_2t = geraMatrizC_2t(120);
t160_2t = geraMatrizC_2t(160);
t200_2t = geraMatrizC_2t(200);

cout << "Matriz 12x12 usando 2 threads = " << t12_2t << endl;
cout << "Matriz 20x20 usando 2 threads = " << t20_2t << endl;
cout << "Matriz 40x40 usando 2 threads = " << t40_2t << endl;
cout << "Matriz 80x80 usando 2 threads = " << t80_2t << endl;
cout << "Matriz 100x100 usando 2 threads = " << t100_2t << endl;
cout << "Matriz 120x120 usando 2 threads = " << t120_2t << endl;
cout << "Matriz 160x160 usando 2 threads = " << t160_2t << endl;
cout << "Matriz 200x200 usando 2 threads = " << t200_2t << endl;

// 4 THREADS ----------------------------------------------------------------------------------------------------------------
t12_4t = geraMatrizC_4t(12);
t20_4t = geraMatrizC_4t(20);
t40_4t = geraMatrizC_4t(40);
t80_4t = geraMatrizC_4t(80);
t100_4t = geraMatrizC_4t(100);
t120_4t = geraMatrizC_4t(120);
t160_4t = geraMatrizC_4t(160);
t200_4t = geraMatrizC_4t(200);

cout << "Matriz 12x12 usando 4 threads = " << t12_4t << endl;
cout << "Matriz 20x20 usando 4 threads = " << t20_4t << endl;
cout << "Matriz 40x40 usando 4 threads = " << t40_4t << endl;
cout << "Matriz 80x80 usando 4 threads = " << t80_4t << endl;
cout << "Matriz 100x100 usando 4 threads = " << t100_4t << endl;
cout << "Matriz 120x120 usando 4 threads = " << t120_4t << endl;
cout << "Matriz 160x160 usando 4 threads = " << t160_4t << endl;
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
