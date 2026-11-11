#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector <pair <int, char>> a;
char last = 'a' - 1;
int tot = 0;
int ans = 0;
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    a.push_back ({0, '0'}); // to use 1_base
    for (int i = 1; i <= n; i++) {
        int s;
        char c;
        cin >> s >> c;
        if (c == last)
            tot += s;
        else {
            if (last != 'a' - 1)
                a.push_back ({tot, last});
            last = c;
            tot = s;
        }
    }
    if (last != 'a' - 1)
        a.push_back ({tot, last});
    n = a.size() - 1;
    int head = 1, tail = n;
    while (head < tail) {
        if (a[head].second == a[tail].second) {
            if (a[head].first == a[tail].first)
                head++, tail--;
            else if (a[head].first > a[tail].first) {
                a[head].first -= min (a[head].first, a[tail].first);
                tail--;
            }
            else {
                a[tail].first -= min (a[head].first, a[tail].first);
                head++;
            }
        }
        else {
            if (a[head].first == a[tail].first) {
                ans += a[head].first;
                head++, tail--;
            }
            else if (a[head].first < a[tail].first) {
                ans += a[head].first;
                a[tail].first -= a[head].first;
                head++;
            }
            else {
                ans += a[tail].first;
                a[head].first -= a[tail].first;
                tail--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
