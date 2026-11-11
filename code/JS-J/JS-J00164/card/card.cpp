#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=5e5+5,M=3e5+5;
int a[N],c[M],ans[M];
vector<int> g[M];
int n,m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i);
        c[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=g[i].back();j<=n;j++)
        {
            ans[a[j]]+=c[i];
            j=g[a[j]].back();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}