#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int last[N];
int lst[N];
bool f[N];
int cnt[N];
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    memset (lst, -1, sizeof(lst));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        memset(f, true, sizeof(f));
        for (int j = i; j <= n; j++)
        {
            if (last[j] >= i && f[last[j]])
            {
                for (int k = last[j]; k < j; k++)
                {
                    f[k] = false;
                }
            }
        }
        for (int j = i; j<= n; j++)
        {
            if (f[j])
            {
                cnt[a[j]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
