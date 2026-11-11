#include <iostream>
#include <algorithm>
using namespace std;

int a[500005];
int b[500005];
int ans[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int t;
            for (int k = 1; k <= n; k++)
            {
                if (a[k] == a[j])
                {
                    t = k;
                    break;
                }
            }
            if (a[t] != 0)
            {
                for (int k = t; k <= n; k++)
                {
                    a[k] = 0;
                }
                a[t] = b[j];
            }
            else a[t+1] = b[j];
        }

        for (int j = 1; j <= n; j++)
        {
            ans[a[j]]++;
            if (ans[a[j]] > i) ans[a[j]]--;
        }
        for (int j = 1; j <= n; j++)
        {
            a[j] = b[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
