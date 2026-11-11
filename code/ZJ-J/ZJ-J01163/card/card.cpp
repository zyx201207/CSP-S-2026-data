#include<bits/stdc++.h>
using namespace std;
int pai[300005];
int card[500005];
int k[300005];
int dask[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i+=1){
        scanf("%d",&card[i]);
    }
    for(int i=1;i<=n;i+=1){
        int tail=0;
        int pai1=0;
        for(int j=0;j<=m;j+=1){
            pai[j]=0;
        }
        for(int j=i;j<=n;j+=1){
            pai1=card[j];
            if(pai[pai1]!=0){
                for(int x=pai[pai1]+1;x<tail;x+=1){
                    pai[dask[x]]=0;
                }
                tail=pai[j];
                dask[tail]=pai1;
            }
            else{
                tail+=1;
                dask[i]=pai1;
            }
        }
        for(int j=1;j<=tail;j+=1){
            k[dask[j]]+=1;
        }
    }
    for(int i=1;i<=m;i+=1){
        printf("%d ",k[i]);
    }
}