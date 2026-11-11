#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define ls p<<1
#define rs p<<1|1
#define rst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define int long long
#define btp __builtin_popcount
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N(505);
const int M(5e5+5);

int n,m,d,q,ti[M],dis[N][N];
struct node{
    int u,t;
};
vector <node> vec[M];

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    rst(dis,0x3f);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>ti[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int u,t;cin>>u>>t;
            vec[u].pb({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<vec[i].size();j++){
            auto [u,t1]=vec[i][j];
            for(int k=j+1;k<vec[i].size();k++){
                auto [v,t2]=vec[i][k];
                cmin(dis[u][v],t1+t2);
                cmin(dis[v][u],t1+t2);
                // cout<<u<<' '<<v<<" "<<t1+t2<<'\n';
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        if(u==v){
            cout<<"0\n";
            continue;
        }
        int ans=inf;
        // cout<<"???"<<vec[u].size()<<' '<<vec[v].size()<<'\n';
        for(auto [x,t1]:vec[u]){
            for(auto [y,t2]:vec[v]){
                // cout<<x<<' '<<y<<' '<<t1+t2+dis[x][y]<<'\n';
                cmin(ans,t1+t2+dis[x][y]);
            }
        }
        ans+=ti[u]+ti[v];
        cout<<ans<<'\n';
    }
    return 0;
}