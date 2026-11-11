#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int w[300010],ans[300010];
bitset<3010> vis[500010];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=n;i>=1;i--){
    if(w[a[i]]==0) vis[i]=vis[i+1],vis[i][a[i]]=1;
    else vis[i]=vis[w[a[i]]];
    w[a[i]]=i;
    for(int j=1;j<=m;j++){
        if(vis[i][j]==1) ans[j]++;
    }
}
for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
return 0;
}
