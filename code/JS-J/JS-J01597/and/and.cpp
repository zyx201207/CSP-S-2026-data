#include <bits/stdc++.h>
using namespace std;
int a[200001],dp[2001][2001],n,m,sum,ans = 0;
void dfs(int dep,int sum,int s)
{
    if (dep > n)
    {
        ans = max(ans,s);
        return;
    }
    if (sum < m)
    {
        if (sum != 0)
        {
            dfs(dep+1,sum+1,s&a[dep]);
        }
        else
        {
            dfs(dep+1,sum+1,a[dep]);
        }
    }
    if (!(n-dep+1 == m-sum))
    {
        dfs(dep+1,sum,s);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (m == 2 || m == n-1 || m == 1 || m == n)
    {
        if (m == 2)
        {
            for (int i = 1;i<=n;i++)
            {
                for (int j = i+1;j<=n;j++)
                {
                    if (a[i]&a[j] > ans)
                    {
                        ans = a[i]&a[j];
                    }
                }
            }
        }
        else if (m == n-1)
        {
            for (int i = 1;i<=n;i++)
            {
                int s = 0,t = 0;
                for (int j = 1;j<=n;j++)
                {
                    if (j != i)
                    {
                        t++;
                        if (t == 1)
                        {
                            s = a[j];
                        }
                        else
                        {
                             s = s&a[j];
                        }
                    }
                }
                ans = max(ans,s);
            }
        }
        else if (m == 1)
        {
            for (int i = 1;i<=n;i++)
            {
                ans = max(ans,a[i]);
            }
        }
        else
        {
            for (int i = 1;i<=n;i++)
            {
                if (i != 1)
                {
                    ans = ans&a[i];
                }
                else
                {
                    ans = a[i];
                }
            }
        }
    }
    else if (n <= 2000)
    {
        dfs(1,0,0);
    }
    else
    {
        ans = a[n-m+1];
    }
    cout << ans;
    return 0;
}
