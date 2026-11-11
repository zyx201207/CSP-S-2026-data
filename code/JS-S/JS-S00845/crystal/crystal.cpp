#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int N = 5e5 + 5;

long long n, m, ans, now, cnt, nn = -1;
long long a[N], b[N];

map<long long, int> mp;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    long long tmp = 5e12 + 5, sa = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != tmp) {
            mp[tmp] = i - sa;
            b[++nn] = tmp;
            tmp = a[i];
            sa = i;
        }
    }
    b[0] = 0;
    mp[0] = 0;
    mp[tmp] = n + 1 - sa;
    b[++nn] = tmp;

    //for (int i = 0; i <= nn; i++) {
    //    cout << i << ' ' << b[i] << ' ' << mp[b[i]] << endl;
    //}

    int l = nn, r = nn;
    cnt = mp[b[nn]];
    now = m;
    ans = max(ans, cnt);
    while (l >= 1) {
        //cout << l << ' ' << r << ' ' << now << ' ' << cnt << ' ' << ans << endl;
        if (1ll * mp[b[l - 1]] * (b[r] - b[l - 1]) <= now) {
            l--;
            now -= 1ll * mp[b[l]] * (b[r] - b[l]);
            cnt += mp[b[l]];
            ans = max(ans, cnt);
        } else {
            cnt += 1ll * now / (b[r] - b[l - 1]);
            ans = max(ans, cnt);
            cnt -= 1ll * now / (b[r] - b[l - 1]);
            r--;
            cnt -= mp[b[r + 1]];
            now += 1ll * cnt * (b[r + 1] - b[r]);
            ans = max(ans, cnt);
        }
        if (now > m) {
            now = m;
        }
        if (l > r) {
            l--;
            now -= 1ll * mp[b[l]] * (b[r] - b[l]);
            cnt += mp[b[l]];
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}
