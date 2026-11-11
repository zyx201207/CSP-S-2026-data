#include<bits/stdc++.h>
using namespace std;
int desk[20000];
int res[20000];
int temp[5000];
int allres[5000][30000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int time1=0;
    int card=0;
    int last_t=0;
    int last_r=0;
    cin>>time1;//=n
    cin>>card;//=m
    int cnt=0;
    for(int i=0;i<=time1;i++){
        cin>>desk[i];

    }
    for(int s=0;s<=time1;s++){
    for(int i=0;i<=time1;i++){
        temp[last_t]=desk[i-s];
        last_t+=1;
        for(int j=0;j<=i;j++){
            if(desk[i-s]==res[j]){
                for(int k=0;k<=4999;k++){
                    temp[k]=0;

                }
                last_t=0;
                res[last_r]=desk[i];
                last_r+=1;
                break;
            }

        }
        if(last_t!=0){
            for(int i=0;i<=last_t;i++){
                res[last_r]=temp[i];
                last_r+=1;
            }
            for(int k=0;k<=4999;k++){
                temp[k]=0;

            }
            last_t=0;

        }

        }
        for(int j=0;j<=last_r;j++){

            allres[s][j]=res[j];

        }


    }
    for(int i=0;i<card;i++){

        for(int j=0;j<time1;j++){
            for(int s=0;s<card;s++){
                if(allres[j][s]==i+1){
                    cnt+=1;
                    break;
                }
            }
        }
        cout<<cnt<<' ';
        cnt=0;

    }





    fclose(stdin);
    fclose(stdout);
    return 0;


    }



