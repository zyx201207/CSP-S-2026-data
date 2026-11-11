#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],lst[N];
vector<int> edges[N];
void dfs(int x)
{
    int t=edges[x].size();
    for(int i=0;i<t;i++)
    {
        int v=edges[x][i];
        dfs(v);
        sum[x]+=sum[v];
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
        sum[a[i]]++;
    }
    for(int i=n;i>=1;i--)
    {
        if(lst[a[i]]!=i) continue;
        if(i!=n) edges[a[i+1]].push_back(a[i]);
    }
    dfs(a[n]);
    for(int i=1;i<=m;i++)
    {
        cout<<sum[i];
        if(i!=m) cout<<" ";
    }
    return 0;
}
