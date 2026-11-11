#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[500005], counts[300005], b[500005];

ll get_index(int x, int end)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= end; i++)
    {
        if (b[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int l = 1; l <= n; l++)
    {
        int end = 0; // For end & number of b
        for (int i = l; i <= n; i++)
        {
            int indexai = get_index(a[i], end);
            if (indexai == -1)
            {
                b[++end] = a[i];
            }
            else
            {
                end = indexai - 1;
                b[++end] = a[i];
            }
        }
        for (int i = 1; i <= end; i++)
        {
            // cout << b[i] << ' ';
            counts[b[i]] ++;
        }
        //cout << endl;
        memset(b, 0, sizeof(b));
    }
    for (int i = 1; i <= m; i++)
        cout << counts[i] << ' ';
    return 0;
}
