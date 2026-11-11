#include<bits/stdc++.h>
#define rep(i,l,r) for(int qwp=(r),i=(l);i<=qwp;i++)
#define per(i,r,l) for(int qwp=(l),i=(r);i>=qwp;i--)
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;typedef pair<int,int> pii;
constexpr ll llinf=3e18;
constexpr int N=505,M=5e5+5;
inline void chkmin(ll &x,ll y){x=x<y?x:y;}
int csi,n,m,d,q;
int w[M];vector<pii>g[M];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>csi>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
    rep(i,1,n){
        int k;cin>>k;while(k--){
            int x,y;cin>>x>>y;
            g[x].pb({i,y});
        }
    }
    rep(i,1,n)rep(j,1,n)dis[i][j]=llinf;rep(i,1,n)dis[i][i]=0;
    rep(i,1,m)for(auto p:g[i])for(auto q:g[i])chkmin(dis[p.fir][q.fir],p.sec+q.sec);
    rep(k,1,n)rep(i,1,n)rep(j,1,n)chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;cin>>x>>y;ll ans=llinf;
        for(auto p:g[x])for(auto q:g[y])chkmin(ans,w[x]+p.sec+dis[p.fir][q.fir]+q.sec+w[y]);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
ulimit -v 1048576;ulimit -s 1048576
g++ -O2 -std=c++14 -static subway.cpp -o %;size %;time ./%
ulimit -s 1048576
g++ -O2 -std=c++14 -fsanitize=address,leak,undefined subway.cpp -o %;size %;time ./%
*/