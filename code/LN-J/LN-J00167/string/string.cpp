#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, char> PIC;
deque<PIC> q;
int n, x, ans;
char s[2];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%s", &x, s);
        q.push_back({x, s[0]});
    }
    while (q.size() > 1) {
        PIC u = q.front(), v = q.back();
        if (u.second ^ v.second) {
            ans += min(u.first, v.first);
        }
        q.pop_back();
        q.pop_front();
        if (u.first < v.first) {
            q.push_back({v.first - u.first, v.second});
        } else if (u.first > v.first) {
            q.push_front({u.first - v.first, u.second});
        }
    }
    printf("%lld", ans);
    return 0;
}
