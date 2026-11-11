#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define dep(i, a, b) for (ll i = (a); i >= (b); i--)
#define il inline
using namespace std;
constexpr int MAXN = 2e5 + 5;
ll a[MAXN], ans;
int n, pos1 = 1, pos2;
char ch[MAXN], nxt;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    IOS;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        cin >> ch[i];
    }
    pos2 = n;
    while (pos1 <= pos2) {
        if (ch[pos1] == ch[pos2]) {
            if (a[pos1] > a[pos2]) {
                a[pos1] -= a[pos2];
                pos2--;
            }
            else if (a[pos1] == a[pos2]) {
                pos1++;
                pos2--;
            }
            else {
                a[pos2] -= a[pos1];
                pos1++;
            }
        } else {
            if (a[pos1] > a[pos2]) {
                a[pos1] -= a[pos2];
                ans += a[pos2];
                pos2--;
            }
            else if (a[pos1] == a[pos2]) {
                ans += a[pos1];
                pos1++;
                pos2--;
            }
            else {
                a[pos2] -= a[pos1];
                ans += a[pos1];
                pos1++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
