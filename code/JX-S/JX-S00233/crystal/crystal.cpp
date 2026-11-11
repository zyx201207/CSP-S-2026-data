
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[500005], ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll head = 1, tail = 1, maxl = 1, len = 1;
    while (tail <= n)
    {
        tail++;
        len++;
        ll s = 0;
        for (int i = head; i <= tail; i++) s += a[tail] - a[i];
        //cout << s << "\n";
        while(m < s)
        {
            s -= a[tail] - a[head];
            head++;
            len--;
        }
        maxl = max(maxl, min(len, n));
    }
    cout << maxl;
    return 0;
}
