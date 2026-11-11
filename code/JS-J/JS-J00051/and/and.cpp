#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
long long num[N], f[N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i < j) f[j] = 0;
            else if (j == 1) f[j] = num[i];
            else f[j] = max(f[j], f[j - 1] & num[i]);
        }
    }
    cout << f[m];
    return 0;
}
