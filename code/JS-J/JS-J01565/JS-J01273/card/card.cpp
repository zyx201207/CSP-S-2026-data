#include <bits/stdc++.h>
using namespace std;
int a[500010];bool vis[500010];int cnt[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,m);
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                memset(vis,0,m);
            }
            vis[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            //cout<<vis[j]<<endl;//ddddddddddd
            if(vis[j]) cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
