#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 510
int tc,n,m,d,q,dis[N][N],w[501114];
vector<pair<int,int>>gua[501114];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>tc>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
    rep(i,1,n){
        int k;cin>>k;
        rep(j,1,k){
            int x,tim;cin>>x>>tim;
            gua[x].push_back({i,tim});
        }
    }
    rep(i,1,n)rep(j,1,n)dis[i][j]=1e16;
    rep(i,1,n)dis[i][i]=0;
    rep(i,1,m){
        rep(j,0,(int)(gua[i].size())-1)rep(k,j+1,(int)(gua[i].size()-1)){
            int w=min(dis[gua[i][j].first][gua[i][k].first],gua[i][j].second+gua[i][k].second);
            dis[gua[i][j].first][gua[i][k].first]=dis[gua[i][k].first][gua[i][j].first]=w;
        }
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y,ans=1e16;
        cin>>x>>y;
        rep(i,0,(int)(gua[x].size())-1)rep(j,0,(int)(gua[y].size()-1)){
            ans=min(ans,dis[gua[x][i].first][gua[y][j].first]+gua[x][i].second+gua[y][j].second);
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}