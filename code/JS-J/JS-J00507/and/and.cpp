#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[1000010];
int fac[40];
unordered_set <int> s;
int answer = 0;
vector <int> temp;
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s.insert(i);
    fac[0] = 1;
    for (int i = 1; i <= 35; i++)
        fac[i] = fac[i - 1] * 2;
    for (int i = 30; i >= 1; i--) {
        int cnt = 0;
        for (auto y : s)
            cnt += ((a[y] >> (i - 1)) & 1);
        if (cnt >= m) {
            answer += fac[i - 1];
            temp.clear();
            for (auto y : s)
                if (((a[y] >> (i - 1)) & 1) == 0)
                    temp.push_back (y);
            for (auto y : temp)
                s.erase (y);
        }
    }
    cout << answer << '\n';
    return 0;
}
