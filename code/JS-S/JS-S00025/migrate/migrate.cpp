#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); i <= (e); i++)
#define dep(i, s, e) for (int i = (s); i >= (e); i--)
#define sz(x) (int)x.size()
#define ppc(x) __builtlin_popcnt(x)
#define pub push_back
using namespace std;

const int N = 2e6 + 5;
#define int long long
#define ll long long
#define i28 __int128

int x[N], f0[N], f1[N], f2[N], f3[N], nx[N], ls[N];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cid, ts;
    cin >> cid >> ts;
    while (ts--)
    {
        int n, d;
        cin >> n >> d;
        rep(i, 1, n)
            cin >> x[i];
        
        int j = 1;
        rep(i, 1, n)
        {
            while (j < n && x[j + 1] - x[i] <= d) j++;
            nx[i] = j;
            f0[j]++;
        }
        j = n;
        dep(i, n, 1)
        {
            while (j > 1 && x[i] - x[j - 1] <= d) j--;
            ls[i] = j;
        }
        
        int ans = 0;

        rep(i, 1, n)
        {
            f1[i] = 1 + (nx[i] != nx[i - 1]) * ((nx[ls[i]] == i) * f1[ls[i]] + f0[i]);
            if (ls[i] == i) continue;
            f2[i] = (ls[ls[i]] != ls[i] && nx[ls[ls[i]]] == ls[i] + 1) * f1[ls[ls[i]]] + f3[ls[i]];
            f3[i] = (nx[i] != nx[i - 1] && nx[ls[i]] == i) * ((ls[ls[i]] != ls[i]) * f1[ls[ls[i]]] + f3[ls[i]]);
        }

        rep(i, 1, n)
            ans += f2[i];//, cout << f1[i] << " \n"[i == n];
        cout << ans << "\n";

        rep(i, 1, n)
            f1[i] = f2[i] = f3[i] = nx[i] = ls[i] = 0;
    }
    return 0;
}