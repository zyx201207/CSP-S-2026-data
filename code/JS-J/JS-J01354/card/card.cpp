#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=500005;
int a[N];
int n,m;
int last[N];
vector<int> G[N];
int sz[N];
int ans[N];
void dfs(int x){
    sz[x]=1;
    for(int i=0;i<G[x].size();i++){
        dfs(G[x][i]);
        sz[x]+=sz[G[x][i]];
    }
    ans[a[x]]+=sz[x];
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        if(last[a[i]]==0){
            G[i+1].push_back(i);
            last[a[i]]=i;
        }else G[last[a[i]]+1].push_back(i);
    }
    dfs(n+1);
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}