#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int a[maxn];
bool b[maxm];
vector<int> g[maxn];
int ans[maxm];
void dfs(int pos){
    for(int i=0;i<(int)g[pos].size();++i){
        dfs(g[pos][i]);
        ans[pos]+=ans[g[pos][i]];
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        ++ans[a[i]];
    }
    for(int i=n-1;i>=0;--i){
        if(b[a[i]]) continue;
        b[a[i]]=1;
        g[a[i+1]].push_back(a[i]);
    }
    dfs(a[n-1]);
    for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}