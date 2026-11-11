#include<bits/stdc++.h>
using namespace std;
int n,m,wz[3005],a[5005],cnt[3003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)wz[j]=0;
        int last=1;
        for(int j=i;j<=n;j++){
            if(!wz[a[j]]){
                wz[a[j]]=last;
                last++;
            }
            if(wz[a[j]]){
                for(int k=1;k<=m;k++){
                    if(wz[k]>wz[a[j]])wz[k]=0;
                }
                last=wz[a[j]]+1;
            }
        }
        for(int j=1;j<=m;j++){
            if(wz[j]){
                cnt[j]++;
                // cout<<i<<" ";
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}