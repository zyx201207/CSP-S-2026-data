#include <iostream>
#include <algorithm>
using namespace std;

int a[500010], ans[300010];

int pos[300010], cds[500010], top;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        fill(pos + 1, pos + m + 1, 0);
        fill(cds + 1, cds + n + 1, 0);
        top = 0;
        for (int j = i; j <= n; j++)
        {
            if (pos[a[j]] != 0)
            {
                int tmp = pos[a[j]];
                for (int k = pos[a[j]]; k <= top; k++)
                    pos[cds[k]] = 0;
                top = tmp;
            }
            pos[a[j]] = ++top;
            cds[top] = a[j];
        }
        for (int j = 1; j <= m; j++)
            if (pos[j] != 0)
                ans[j]++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ' ;

    cout << '\n';
    return 0;
}
