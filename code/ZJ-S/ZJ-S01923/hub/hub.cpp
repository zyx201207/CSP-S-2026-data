#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=LONG_LONG_MAX/4;
const int N=1e6+10,RN=1e6;
int cid,T,n,k;
int cnt,ans;
int d[N];
int bl[N];
pii e[N];
vector<pii> to[N];
vector<int> leaf;
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].pb({v,i}),to[v].pb({u,i});
        e[i]={u,v};
    }
    int sum=n;
    ans=inf;
    if(n==k) ans=0;
    for(int i=1;i<n;i++){
        leaf.clear();
        for(int j=1;j<=n;j++) d[j]=0;
        for(int j=1;j<n;j++){
            auto [u,v]=e[j];
            if(j!=i) d[u]++,d[v]++;
        }
        for(int i=1;i<=n;i++){
            if(d[i]==1) leaf.pb(i);
        }
        sum=n;
        for(int res=1;res<=n;res++){
            vector<int> nleaf;
            for(auto u:leaf){
                d[u]--;
                bool chk=0;
                for(auto [v,id]:to[u]){
                    if(id==i) continue;
                    d[v]--;
                    if(d[v]==1){
                        nleaf.pb(v);
                    }
                    if(d[v]>=0) chk=1;
                }
                if(chk) sum--;
            }
            leaf=nleaf;
            if(sum<=k){
                // cerr<<i<<' '<<res<<'\n';
                ans=min(ans,res);
                break;
            }
        }
    }
    cout<<ans<<'\n';
    ans=cnt=0;
    for(int i=1;i<=n;i++) bl[i]=d[i]=0;
    for(int i=1;i<=n;i++) to[i].clear();
    leaf.clear();
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>cid>>T;
    while(T--){
        solve();
    }
    return 0;
}