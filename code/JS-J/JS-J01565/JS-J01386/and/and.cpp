#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200010],vis[200010];
void dfs(int step)
{
    if(step>n)
    {
        int n,ct = 0;
        for(int i = 0;i<m;i++)
        {
            if(vis[i]!=0)
            {
                if(ct==0)
                {
                    n = a[i];
                }
                n&=a[i];
                ct++;
            }
        }
        maxn = max(n,maxn);
        return;
    }
    for(int i = 0;i<m;i++)
    {
        vis[step] = i;
        dfs(step+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<maxn;
    return 0;
}
