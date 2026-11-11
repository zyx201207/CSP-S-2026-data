#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,ans = 1000000000012;
ll w[500005],a[502][20005],t[502][20005],k[500005];
bool vis[500005];
struct station{
    ll line, tm;
};
vector<vector<station>> st;
void dfs(ll u, ll v, ll sum){
    if(u==v){
        ans = min(ans,sum);
        return;
    }
    if(vis[u])return;
    for(auto i : st[u])
    {
        for(int j = 1; j <= k[i.line]; j ++)
        {
            dfs(a[i.line][j],v,sum+i.tm);
        }

    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    st.resize(m);
    for(ll i = 1; i <= m; i ++)cin>>w[i];
    for(ll i = 1; i <= n; i ++){
        cin>>k[i];
        for(ll j = 1; j <= k[i]; j ++){
            cin>>a[i][j]>>t[i][j];
            st[a[i][j]].push_back({i,t[i][j]});
        }
    }
    while(q--){
        memset(vis,0,sizeof vis);
        ll x, y;
        dfs(x,y,0);
        cout << ans+w[x]+w[y] << '\n';
    }
    return 0;
}
