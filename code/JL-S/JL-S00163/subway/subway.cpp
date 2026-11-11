#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int mp[510][510],w[510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++) cin>>w[i];
memset(mp,0x13f,sizeof(mp));
for(int i=1;i<=m;i++) mp[i][i]=0;
for(int i=1,x;i<=n;i++){
        cin>>x;
        int a[501],t[501];
        for(int j=1;j<=x;j++){
                cin>>a[j]>>t[j];
            for(int k=1;k<j;k++){
                mp[a[j]][a[k]]=min(mp[a[j]][a[k]],t[k]+t[j]);
                mp[a[k]][a[j]]=min(mp[a[k]][a[j]],t[j]+t[k]);
         //       cout<<j<<' '<<k<<" "<<mp[a[j]][a[k]]<<"\n";
            }
        }
}
for(int k=1;k<=m;k++){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++) {
            mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
        }
    }
}
int u,v;
while(q--){
    cin>>u>>v;
    cout<<mp[u][v]+w[u]+w[v]<<"\n";
}
return 0;
}
