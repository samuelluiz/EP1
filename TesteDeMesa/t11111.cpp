#include <iostream>
#include <random>
#include <thread>
#define n
#define matA[200][200]
#define matB[200][200]
#define matC[200][200]

using namespace std;

int n;

//MATRIZ A
void geraMatrizA(){
    //Configura qual é o gerador
    default_random_engine gerador;
    //Configura qual é o intervalo (nesse caso de 1 até 100)
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
    //Configura qual é o gerador
    default_random_engine gerador;
    //Configura qual é o intervalo (nesse caso de 1 até 100)
uniform_int_distribution <int> distribuicao(1,10);

    int l, c;
    n =200;
    for(l=0; l<n; l++){
    for(c=0; c<n; c++){
        matB[l][c] = distribuicao(gerador);
    }
}
}

void geraMatrizC_12x12(){
    n = 12;
    int l, c,x;
    thread t1_12x12{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n/2; c++){
            matC[l][c]=0;
            for(x=0; x<n/2; x ++){
                    aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
   }}};
   thread t2_12x12{[&](){
    for(l=n/2; l<n; l++){
    for(c=n/2; c<n; c++){
            matC[l][c]=0;
            for(x=n/2; x<n; x ++){
                    aux += matA[l][x] * matB[x][c];
            }
            matC[l][c]= aux;
            aux = 0;
    }
   }}};
   t2_12x12.join();
   t1_12x12.join();
}
int main(){
    //Configura qual é o gerador
    default_random_engine gerador;
    //Configura qual é o intervalo (nesse caso de 1 até 100)
uniform_int_distribution <int> distribuicao(1,10);

int matA[2][2], matB[2][2], matC[2][2], aux=0;
int l, c, x;

/*MATRIZ A
for(l=0; l<2; l++){
    for(c=0; c<2; c++){
        matA[l][c] = distribuicao(gerador);
    }
}

//MATRIZ B
for(l=0; l<2; l++){
    for(c=0; c<2; c++){
        matB[l][c] = distribuicao(gerador);
    }
}

//MATRIZ C

thread tfor{[&](){
    for(l=0; l<2; l++){
    for(c=0; c<2; c++){
            matC[l][c]=0;
            for(x=0; x<2; x ++){
                thread tMult{[&](){
                    aux += matA[l][x] * matB[x][c];
                }};
                tMult.join();
            }
            matC[l][c]= aux;
            aux = 0;
    }

}}};
tfor.join();

*/
//PRINTS
for(int l=0; l<12; l++){
    for( c=0; c<12; c++){
        cout << "|"<< matA[l][c] << "|";
    }
    cout << endl;
}
cout<< endl;

for(int l=0; l<12; l++){
    for( c=0; c<12; c++){
        cout << "|"<< matB[l][c] << "|";
    }
    cout << endl;
}
cout<<endl;

for(int l=0; l<12; l++){
    for( c=0; c<12; c++){
        cout << "|"<< matC[l][c] << "|";
    }
    cout << endl;
}
return 0;
}
