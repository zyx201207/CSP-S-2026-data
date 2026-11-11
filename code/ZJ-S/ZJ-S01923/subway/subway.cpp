#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int inf=LONG_LONG_MAX/4;
const int N=5e5+10,RN=5e5;
int T,c,n,m,d,q;
int len[N],w[N];
int f[505][505];
vector<pii> sta[N];
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            int x,y;
            cin>>x>>y;
            sta[x].pb({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=inf;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto [u,dis1]:sta[i]){
            for(auto [v,dis2]:sta[i]){
                f[u][v]=min(f[u][v],dis1+dis2);
                f[v][u]=f[u][v];
                // cerr<<u<<' '<<v<<'\n';
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]+f[k][j]<f[i][j]){
                    f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=inf;
        for(auto [x,dis1]:sta[u]){
            for(auto [y,dis2]:sta[v]){
                int tmp=dis1+dis2+min(f[y][x],f[x][y]);
                ans=min(ans,tmp);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<'\n';
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    T=1;
    while(T--){
        solve();
    }
    return 0;
}