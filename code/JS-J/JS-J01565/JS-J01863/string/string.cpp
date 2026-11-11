#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, char> PII;
const int N = 2e5;
int n;
PII a[N + 10];
int len[N + 10];
int pre, suf;
int ans;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
        len[i] = len[i - 1] + a[i].first;
    }
    len[n + 1] = len[n];
    pre = 1;
    suf = n;
    while (pre < suf) {
        if (a[pre].second == a[suf].second) {
            if (len[pre] > len[n] - len[suf - 1])
                suf --;
            else pre ++;
        }
        else {
            int xsuf = len[n] - len[suf - 1];
            int nsuf = len[n] - len[suf];
            ans += min(len[pre], xsuf) - max(nsuf, len[pre- 1]);
            if (len[pre] > len[n] - len[suf - 1])
                suf --;
            else pre ++;
        }
    }

    cout << ans << '\n';
    return 0;
}
