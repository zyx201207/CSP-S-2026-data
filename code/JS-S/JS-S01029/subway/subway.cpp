#include <bits/stdc++.h>
using namespace std;
int w[500005];
long long dis[505][505];
vector<pair<int,int> >ve[500005];
int main(){
    memset(dis,0x3f,sizeof(dis));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        while(len--){
            int pos,val;
            cin>>pos>>val;
            ve[pos].push_back({i,val});
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto [id,l]:ve[i]){
            for(auto [ID,L]:ve[i]){
                dis[id][ID]=min(dis[id][ID],(long long)l+L);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        long long ans=1e18;
        for(auto [id,l]:ve[u]){
            for(auto [ID,L]:ve[v]){
                ans=min(ans,dis[id][ID]+l+L);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}