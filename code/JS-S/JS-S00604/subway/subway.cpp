#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<=(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
typedef pair<int,ll> PIL;
const int MAXN = 500+10;
const int MAXM = 5e5+10;

int c,n,m,d,q;
ll w[MAXM];
vector<PIL> e[MAXM];
//int k[MAXN];
ll dis[MAXN][MAXN];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    //cerr<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<'\n';
    memset(dis,0x3f,sizeof(dis));
    rep(i,1,n)dis[i][i]=0;
    rep(i,1,m){
        cin>>w[i];
    }
    rep(i,1,n){
        int k;
        cin>>k;
        rep(j,0,k-1){
            int aa;ll tt;
            cin>>aa>>tt;
            e[aa].push_back({i,tt});
        }
    }
    rep(i,1,m){
        for(auto& e1:e[i])for(auto& e2:e[i]){
            dis[e1.first][e2.first]=min(dis[e1.first][e2.first],e1.second+e2.second);
        }
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n){
        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--){
        int x,y;ll ans=1e18+10;
        cin>>x>>y;
        for(auto& e1:e[x])for(auto& e2:e[y]){
            ans=min(ans,w[x]+w[y]+e1.second+e2.second+dis[e1.first][e2.first]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}