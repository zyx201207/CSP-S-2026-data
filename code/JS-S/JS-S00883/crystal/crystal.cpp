#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
int a[500010];
long long sa[500010];

bool check(int mid)
{
    for (int i = mid; i <= n; i++)
        if (1ll * mid * a[i] - (sa[i] - sa[i - mid]) <= m)
            return true;
    return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sa[i] = sa[i-1] + a[i];
    int left = 1, right = n;
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if (check(mid))
            left = mid;
        else right = mid - 1;
    }
    cout << left << '\n';
    return 0;
}
