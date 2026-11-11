#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 3;
int C, Q, n, d, a[N];
void init()
{
    cin >> n >> d;
    vector<int> a(n), b(n + 2), c(n + 2);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    for (int i = 1; i <= n; i++)
    {
        b[i] = upper_bound(a.begin(), a.end(), a[i - 1] + d) - a.begin() - 1;
        //cout << b[i] << ' ';
    }
    for (int i = n; i >= 1; i--)
    {
        c[i] = lower_bound(a.begin(), a.end(), a[i - 1] - d) - a.begin();
        //cout << c[i] << ' ';
    }
    //if (a[0] == 0)
        //for (int i = 1; i <= n; i++)
            //cout << '*' << c[i] << " " << b[i] << '\n';
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 3; j <= n; j++)
        {
            int ri = b[i], rj = b[j], li = c[i], lj = c[j];
            //if (a[0] == 0 && a[1] == 3)
            //    cout << i << " " << j << '\n';
            //if (a[0] == 0 && a[1] == 3)
            //    cout << li << " " << ri << " " << lj << " " << rj << '\n';
            if (ri - lj < 1)
            {
                //cout << "*";
                break;
            }
            if (ri - lj == 1)
            {
                //if (a[0] == 0 && a[1] == 3)
                //    cout << "?\n";
                ans++;
                //continue;
            }
        }
    cout << ans << '\n';
    return;

}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> C >> Q;
    for (; Q; Q--) init();
    return 0;
}
