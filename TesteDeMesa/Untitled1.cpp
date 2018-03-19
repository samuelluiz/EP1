#include <iostream>
#include <random>
#include <thread>
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

void geraMatrizC_12x12(){
    n = 12;
    int l, c,x;
    thread t1_12x12{[&](){
    for(l=0; l<n/2; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   thread t2_12x12{[&](){
    for(l=n/2; l<n; l++){
    for(c=0; c<n; c++){
            for(x=0; x<n; x ++){
                    matC[l][c] += matA[l][x] * matB[x][c];
            }
    }
   }}};
   t2_12x12.join();
   t1_12x12.join();

}
int main(){
int l, c;

geraMatrizA();
geraMatrizB();
geraMatrizC_12x12();

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
