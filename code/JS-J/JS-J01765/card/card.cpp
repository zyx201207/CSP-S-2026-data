#include<bits/stdc++.h>
using namespace std;
long n,m,a[5000005],h[3000005],d[5000005];
void card(long i){
    int len=0;
    bool cz[3000005];
    for(;i<=n;i++){
        int wz=5000005;
        for(int j=1;j<=len;j++){
            if(j>wz)len=wz;
            if(d[j]==a[i]){
                wz=j;
            }
        }
        if(wz==5000005){
            len+=1;
            d[len]=a[i];
        }
    }
    for(int k=1;k<=m;k++){
        for(int j=1;j<=len;j++){
            if(d[j]==k){
                h[k]++;
                break;
            }
        }
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        card(i);
    }
    for(int i=1;i<=m;i++)cout<<h[i]<<' ';
    return 0;
}
