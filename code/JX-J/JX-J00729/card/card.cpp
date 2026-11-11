#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005]={0};
int mm[1000005]={0};
int u[1000005]={0};
int oi[1000005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mm[a[i]]=1;
    }
    int w=1;
    for(int i=1;i<=1000000;i++){
        if(mm[i]==1){
            u[w]=i;
            w++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]=a[i-1]){
            a[i]=0;
        }
        bool r=false;
        for(int j=1;j<=n;j++){
            if(mm[i]==a[j]) r=true;
        }
        if(r) oi[i]++;
    }
    for(int i=1;i<=m;i++){
        cout<<oi[i]<<" ";
    }
    //quxiaozhushi
    return 0;
}
