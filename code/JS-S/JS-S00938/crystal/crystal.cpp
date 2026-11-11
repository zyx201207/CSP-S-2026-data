#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 500005;
int n, l, r;
ll m, a[N];
bool check(int x)
{
    ll res = 0;
    for (int i = 1; i < x; i++)
        res += (a[x] - a[i]);
    return res <= m;
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
    l = 1;
    r = n;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}
