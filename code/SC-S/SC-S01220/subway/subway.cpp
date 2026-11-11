#include<bits/stdc++.h>
using namespace std;
using i64=long long;
template<class T>
void Cmin(T &x,const T& y){ x=(x<y?x:y); }
const int N=505,D=20,M=5e5+5;
const i64 INF=0x3f3f3f3f3f3f3f3f;
int sid,n,m,d,q;
i64 w[M],dist[N][N];
vector<pair<int,int>> sta[M];
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>sid>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int x,t;
            cin>>x>>t;
            sta[x].emplace_back(i,t);
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j) dist[i][j]=INF;
    for(int i=1;i<=m;++i){
        assert(sta[i].size()<=d);
        for(auto [x,t1]:sta[i])
            for(auto [y,t2]:sta[i])
                if(x!=y) Cmin(dist[x][y],(i64)t1+t2);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j) Cmin(dist[i][j],dist[i][k]+dist[k][j]);
    for(int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v;
        i64 ans=INF;
        for(auto [x,t1]:sta[u])
            for(auto [y,t2]:sta[v]) Cmin(ans,dist[x][y]+t1+t2+w[u]+w[v]);
        printf("%lld\n",ans);
    }
    fclose(stdin),fclose(stdout);
    return 0;
}