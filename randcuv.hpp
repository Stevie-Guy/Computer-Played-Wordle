#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>
using std::ifstream;
using std::mt19937;
using std::uniform_int_distribution;


int Alegere(){
    int a;
    srand((unsigned)time(NULL));
    ifstream f("cuvinte_wordle.txt");
    rand();
    mt19937 gen(rand()); 
    uniform_int_distribution<> distrib(1, 11454);
    a=distrib(gen);
    while(a>0){
        f.getline(randcuv,7,'\n');
        a--;
    }
    f.close();
}