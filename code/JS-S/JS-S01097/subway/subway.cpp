#include <bits/stdc++.h>
using namespace std;
namespace chennie_bless_me{
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
inline void chmax(T &a,T b){
    if(a<b) a=b;
}
template<typename T>
inline void chmin(T &a,T b){
    if(b<a) a=b;
}
const int N=505,M=5e5+5,D=21,Q=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int testcase,n,m,d,q;
int w[M],k[N];
vector<int> a[M];
vector<ll> t[M];
ll dis[N][N];
void solve(){
    memset(dis,0x3f,sizeof(dis));
    cin>>testcase>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        dis[i][i]=0;
        for(int j=1;j<=k[i];j++){
            int u,c; cin>>u>>c;
            a[u].push_back(i);
            t[u].push_back(c);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=j+1;k<a[i].size();k++){
                chmin(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            ll d=min(dis[i][j],dis[j][i]);
            dis[i][j]=dis[j][i]=d;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                chmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u,v; cin>>u>>v;
        ll ans=inf;
        for(int i=0;i<a[u].size();i++)
            for(int j=0;j<a[v].size();j++){
                chmin(ans,t[u][i]+t[v][j]+dis[a[u][i]][a[v][j]]);
            }
        cout<<ans+w[u]+w[v]<<'\n';
    }
}
void main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
}
int main(){
    assert(freopen("subway.in","r",stdin));
    assert(freopen("subway.out","w",stdout));
    chennie_bless_me::main();
    return 0;
}
