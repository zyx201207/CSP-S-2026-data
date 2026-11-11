#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[500005],e[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    if(a<500){
        for(int i=1;i<=a;i++){//di i ju
            for(int j=i;j<=a;j++){
                d[j]=0;
            }
            for(int j=i;j<=a;j++){//fang chu di j zhang pai
                d[j]=c[j];
                if(j!=i){
                    for(int k=i;k<j;k++){// mei ju you mei you pai he di j zhang pai chong he
                        if(d[k]==d[j]&&d[k]!=-5&&d[j]!=-5&&d[j]!=0&&d[k]!=0){
                            for(int m=k+1;m<=j;m++){
                                d[m]=-5;
                            }
                        }
                    }
                }
            }
            for(int j=i;j<=a;j++){
                if(d[j]>0){
                    e[d[j]]++;
                }
            }
        }
        for(int i=1;i<=500005;i++){
            if(e[i]>0){
                cout<<e[i]<<" ";
            }
        }
    }else {
        for(int i=1;i<=a;i++){
            e[c[i]]++;
        }
        for(int i=1;i<=500005;i++){
            if(e[i]>0){
                cout<<e[i]<<" ";
            }
        }
    }
    return 0;
}
