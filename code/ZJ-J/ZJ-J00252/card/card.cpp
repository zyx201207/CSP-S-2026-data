#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500005;
const int maxm = 300005;

int a[maxn];
vector<int> sons[maxm];
int cnt[maxm];
bool vis[maxm];
int n,m;

void dfs(int u)
{
    for(int v : sons[u])
    {
        dfs(v);
        cnt[u] += cnt[v];
    }
}

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = n;i >= 1;i--)
    {
        if(!vis[a[i]])
        {
            sons[a[i + 1]].emplace_back(a[i]);
        }
        vis[a[i]] = true;
    }
    for(int i = 1;i <= n;i++) cnt[a[i]]++;
    dfs(a[n]);
    for(int i = 1;i <= m;i++) cout<<cnt[i]<<" ";
    cout<<"\n";
}