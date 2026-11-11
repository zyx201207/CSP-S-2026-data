#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int w[M],cnt[M];
ll dis[N][N];
pair<int,int> v[M][20];
void chmin(ll& x,ll y){
    if(y<x)x=y;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            for(int j=0;j<cnt[a];++j){
                chmin(dis[i][v[a][j].first],v[a][j].second+t);
                chmin(dis[v[a][j].first][i],v[a][j].second+t);
            }
            v[a][cnt[a]]={i,t};
            ++cnt[a];
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            ll tmp=dis[j][i];
            if(tmp>1e18)continue;
            for(int k=1;k<=n;++k)
                chmin(dis[j][k],tmp+dis[i][k]);
        }

    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(int i=0;i<cnt[x];++i){
            int tmp=v[x][i].first;
            ll now=1e18;
            for(int j=0;j<cnt[y];++j)
                chmin(now,v[y][j].second+dis[tmp][v[y][j].first]);
            chmin(ans,now+v[x][i].second);
        }

        cout<<ans+w[x]+w[y]<<'\n';
    }
}
