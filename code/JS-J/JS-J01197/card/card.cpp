#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500010], b[500010];
int box[300010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i] = a[i];
        }
        for (int j = i; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (b[k] == a[j]) b[k] = 0;
                for (int x = k; x <= n; x++)
                {
                    b[x] = 0;
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            box[b[j]] += 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << box[i] << " ";
    }
    return 0;
}
