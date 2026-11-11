#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int l[N];
int c[N];
int d[N];
int ans[N];
int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[j] = a[j];
        }
        memset(c , 0 , sizeof(c));
        for (int j = i; j <= n; j++)
        {
            if (l[d[j]] == 0)
            {
                l[d[j]] = j;
            }
            else
            {
                for (int k = l[d[j]]; k < j; k++)
                {
                    d[k] = 0;
                }
                l[d[j]] = j;
            }
        }
        for (int j = i; j <= n; j++)
        {
            c[d[j]]++;
        }
        for (int j = 1; j <= m; j++)
        {
            if (c[j] > 0)
            {
                ans[j]++;
            }
        }
        //for (int i = 1; i <= m; i++)
        //{
        //    cout << ans[i] << " ";
        //}
        //cout << "\n";
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
