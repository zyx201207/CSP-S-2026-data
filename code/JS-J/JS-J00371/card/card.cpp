#include <bits/stdc++.h>
using namespace std;
int num[300005];
int tong[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","s",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){cin>>num[i];}
    if(n<=500 && m<=200){

    for(int i=1;i<=n;i++){
        int pos=0;
        int bianyi[300005]={0};
        for(int j=i;j<=n;j++){


                for(int k=1;k<j;k++){
                    if(bianyi[k]==num[j]){
                        pos=k-1;

                        break;
                    }
                }
               pos+=1;
               bianyi[pos]=num[j];

        }

        for(int o=1;o<=pos;o++){
            tong[bianyi[o]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<' ';
    }
    }

    else{
        bool a=1;
        for(int i=1;i<n;i++){
            if(num[i]>num[i+1])a=0;
        }
        if(a==1){
            for(int i=1;i<=m;i++){
                cout<<i<<' ';
            }
        }
    }
return 0;}
