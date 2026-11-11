#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
const ll INF=1e18+7;
const int maxm=5e5+5;
int c,n,m,d,q,x,y;
ll w[maxm];
vector<pil> a[maxm];
vector<pil> g[maxm];
ll dp[maxm];
ll dfs(int pos,ll cost){
    if(pos==y) return cost;
    ll res=INF;
    for(int i=0;i<(int)g[pos].size();++i){
        int to=g[pos][i].first,cost2=g[pos][i].second;
        if((~dp[to])||dp[pos]+cost+cost<dp[to]){
            dp[to]=dp[pos]+cost+cost2;
            res=min(res,dfs(to,dp[to]));
        }
    }
    return res;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;++i) cin>>w[i];
    for(int i=0;i<n;++i){
        int k;
        cin>>k;
        for(int j=0;j<k;++j){
            int in1,in2;
            cin>>in1>>in2;
            a[i].push_back(make_pair(in1-1,in2-1));
            for(int l=0;l<j;++l){
                g[a[i][j].first].push_back(make_pair(a[i][l].first,a[i][j].second+a[i][l].second));
                g[a[i][l].first].push_back(make_pair(a[i][j].first,a[i][j].second+a[i][l].second));
            }
        }
    }
    while(q--){
        memset(dp,-1,sizeof(dp));
        cin>>x>>y;
        --x,--y;
        dp[x]=0;
        cout<<(w[x]+w[y])+dfs(x,0)<<'\n';
    }
    return 0;
}