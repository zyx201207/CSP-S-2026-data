#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,ll>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define mset multiset
#define ull unsigned long long
#define i128 __int128
#define fixs fixed<<setprecision
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=5e5+10,maxm=500+10;
const ll inf=1e18;
int o,n,m,d,q,w[maxn],vis[maxn];
ll f[maxm][maxm];
vector<pii> p[maxm],vec[maxn];
void solve(){
    cin>>o>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k,p[i].resize(k);
        for(int j=0;j<k;j++) cin>>p[i][j].fi>>p[i][j].sc,vec[p[i][j].fi].pb({i,p[i][j].sc});
        sort(p[i].begin(),p[i].end());
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int z=0,sz=p[j].size();
            ll val=inf;
            for(pii t:p[i]){
                while(z<sz&&p[j][z].fi<t.fi) z++;
                if(t.fi==p[j][z].fi) val=min(val,t.sc+p[j][z].sc);
            }
            f[i][j]=f[j][i]=val;
        }
        f[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    while(q--){
        int x,y;
        ll res=inf;
        cin>>x>>y;
        for(pii p1:vec[x]){
            for(pii p2:vec[y]) res=min(res,p1.sc+p2.sc+f[p1.fi][p2.fi]);
        }
        cout<<res+w[x]+w[y]<<endl;
    }
}
int main(){
    FileIO("subway");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}