#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000001],c[5001][5001],d[5001][5001],k,m;
int n;
void dfs(int dep,int sum)
{
    if (sum == c[k][dep])
    {
        d[k][dep]++;
        //cout << k << " " << dep << "\n";
    }
    //else if (sum > c[k][dep])
   // {
     //   return;
   // }
    for (int i = dep+1;i<=n;i++)
    {
        if (m >= a[i]-a[dep])
        {
            dfs(i,sum+1);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int p,t;
    cin >> p >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1;i<=n;i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        if (p <= 10)
        {
            k = 0;
            ll s = 0;

            for (int i = 1;i<n;i++)
            {
                for (int j = i+1;j<=n;j++)
                {
                    c[i][j] = (a[j]-a[i]+m-1)/m;
                    d[i][j] = 0;
                }
            }
            while(++k && k < n)
            {
                dfs(k,0);
            }
            for (int i = 1;i<n;i++)
            {
                for (int j = i+1;j<=n;j++)
                {
                    if (d[i][j] == 2)
                    {
                        s++;
                    }

                }
            }
            cout << s << "\n";
        }
        else if (p >= 11 && p <= 12)
        {
            int s = 0;
            for (int i = 1;i<n;i++)
            {
                for (int j = i+3;j<=n;j++)
                {
                    s++;
                }
            }
            cout << s << "\n";
        }
    }
    return 0;
}
