#include<bits/stdc++.h>
using namespace std;
void main1();
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--)main1();
}
constexpr int MAXN=4e3+10;
vector<int>g[MAXN];
int fa1[MAXN];
void dfs1(int c)
{
    for(auto i:g[c])if(i!=fa1[c])
    {
        fa1[i]=c;
        dfs1(i);
    }
}

int cut;
void main1()
{
    int n,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==k)
    {
        cout<<0<<'\n';
        return;
    }
    if(n-1==k||n-2==k||n-3==k)
    {
        cout<<1<<'\n';
        return;
    }
    if(n/2<=k)
    {
        cout<<1<<'\n';
        return;
    }
    cout<<((n+1)/2-k)/4+1;
}