#include <iostream>
#include <random>

using namespace std;

int main(){
    //Configura qual é o gerador
    default_random_engine gerador;
    //Configura qual é o intervalo (nesse caso de 1 até 100)
uniform_int_distribution<int> distribuicao(1,10);

int mat[12][12];
int l, c;
for(int l=0; l<3; l++){
    for(c=0;c<3;c++){
        mat[l][c] = distribuicao(gerador);
    }
}

for(int l=0; l<3; l++){
    for(int c=0; c<3; c++){
        cout << mat[l][c] << &quot; &quot;;
    }
    cout << endl;
}
system (&quot;pause>>null&quot;);
}
