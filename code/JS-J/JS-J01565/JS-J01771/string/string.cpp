#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll sum;
struct lbx
{
    ll num;
    char c;
};

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    lbx a[200005];
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].c;
        sum += a[i].num;
    }
    ll ans = 0;
    ll l = 0;
    ll p1 = 1, p2 = n, cnt = 0;
    while (l < (sum + 1) / 2 && p1 != p2)
    {

        l += a[p1].num;
        char f = a[p1].c;
        ll u = a[p1].num;
        while (u > 0)
        {
            if (u - a[p2].num <= 0)
            {
  //              cnt++;
  //              cout << cnt << " : " << l << " " << u << " " << p1 << " " << p2 << " " << ans << " " << a[p1].c << " " << a[p2].c << " " << f << " " << a[p1].num << " " << a[p2].num << "\n";
                a[p2].num -= u;

                if (a[p2].c != f) ans += u;
                if (a[p2].num == 0) p2--;
                u = 0;
                break;
            }
            if (a[p2].c != f) ans += a[p2].num;
            u -= a[p2].num;
     //       cnt++;
     //       cout << cnt << " : " << l << " " << u << " " << p1 << " " << p2 << " " << ans << " " << a[p1].c << " " << a[p2].c << " " << f << " " << a[p1].num << " " << a[p2].num << "\n";

            p2--;
        }
        p1++;
    }
    cout << ans << "\n";
    return 0;
}//24104432
