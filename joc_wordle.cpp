#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<ctime>
#include<chrono>
#include<conio.h>
using namespace std;
using namespace std::chrono;
char randcuv[7],cuvant[7],verde[7]={' ',' ',' ',' ',' '},galben[7]={'1','1','1','1','1'},negru[33],nugalben[150][7];
int lives=6,j=0,v=0,g=0,da;
#include"randcuv.hpp"


int Incercare(){                                                                //verificam literele care sunt bune si cele care nu sunt(
da=0;

    for(int i=0;i<=4;i++){

        if(cuvant[i]!=verde[i]){

            if(cuvant[i]==randcuv[i]){
                verde[i]=cuvant[i];
                v++;

                for(int t=0;t<=4;t++){

                    if(galben[t]==cuvant[i]){
                        galben[t]='1';
                        g--;
                    }

                }

            }else{

                if(strchr(randcuv,cuvant[i])!=NULL && strchr(verde,cuvant[i])==NULL){
                    nugalben[cuvant[i]][i]=cuvant[i];

                    if(strchr(galben,cuvant[i])==NULL){
                        while(galben[g]!='1')g++;
                        galben[g]=cuvant[i];
                        g++;
                    }
                    
                }else{

                    if(strchr(galben,cuvant[i])!=NULL && strchr(randcuv,cuvant[i])!=strrchr(randcuv,cuvant[i])){
                            nugalben[cuvant[i]][i]=cuvant[i];
                            galben[g]=cuvant[i];
                            g++;
                    }else{

                        if(strchr(negru,cuvant[i])==NULL){
                            negru[j]=cuvant[i];
                            j++;
                        }

                    }

                }
    
            }
        
        }

    }

    for(int i=0;i<=4;i++){

        if(verde[i]==cuvant[i]){

            for(int t=0;t<=4;t++){

                if(galben[t]==cuvant[i]){
                    galben[t]='1';
                    g--;
                }

            }

        }else 
            
            if(strchr(randcuv,cuvant[i])==strrchr(randcuv,cuvant[i])){
            nugalben[cuvant[i]][i]=cuvant[i];
            }

        

    }
g=0;
for(int i=0;i<=4;i++){

    if(galben[i]!='1')g++;

}

cout<<cuvant<<"          "<<galben<<"        v="<<v<<"         g="<<g;
lives--;
}                                                                               //)


int main(){
int i,ok,kk,k,ko;
Alegere();                                                                      //alege cuvantul la intamplare cu ajutorul programului randcuv

auto start = high_resolution_clock::now();

printf("Cuvatul secret este %s \n",randcuv);

for(i=1;i<150;i++)
strcpy(nugalben[i],"22222");

ifstream f("cuvinte_wordle.txt");                                                      
negru[0]='\0';

do{
    f.getline(cuvant,7,'\n');
    ok=1;
    kk=0;
    k=0;
    ko=1;

    for(i=0;i<5;i++){

        if(cuvant[i]==verde[i])k++;                           

        if(strchr(galben,cuvant[i])!=NULL)kk++;

        if(strchr(negru,cuvant[i])!=NULL && strchr(verde,cuvant[i])==NULL)ok=0;                                          //verifica daca exista litere inutile in cuvant

        if(nugalben[cuvant[i]][i]==cuvant[i])ko=0;
    }

    if(ok==1){
        
        if(k==v && kk==g && ko==1){Incercare();
        cout<<"             kk="<<kk<<'\n';}

    }
    if(f.eof()){cout<<"\nFinal\n"<<g<<"         "<<kk<<'\n';break;}




}while(!(strcmp(verde,randcuv)==0 || lives<0));

if(lives<0)printf("Loss");

else printf("Cuvantul este %s",verde);

cout<<"\n\n";
printf("verde=%s galben=%s negru=%s",verde,galben,negru);          
cout <<"\n";
printf("Press any key to exit.");
getch();
f.close();
}