#include <bits/stdc++.h>
using namespace std;

const int M=2e5+5;
bool vis[M];int n,m,maxn=-1,a[M];

void dfs(int step,int ans)
{
    if (step>m)
    {
        maxn=max(maxn,ans);
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==0)
        {
            vis[i]=1;
            dfs(step+1,ans&a[i]);
            vis[i]=0;
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dfs(1,2147483647);
    cout << maxn;
    return 0;
}
