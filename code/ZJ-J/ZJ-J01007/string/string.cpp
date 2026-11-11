#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 200005;
struct node {
    ll cnt;
    char ch;
}a[maxn];
int n;
ll pre[maxn];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].cnt >> a[i].ch;
        sum += a[i].cnt;
        pre[i] = pre[i - 1] + a[i].cnt;
    }
    ll posl = 1, posr = sum;
    int l = 1, r = n;
    ll ans = 0;
    while (l < r && posl < posr) {
        posl = a[l].cnt;
        ll need = a[l].cnt;
        while (posr - pre[r - 1] <= need && need) {
            need -= (posr - pre[r - 1]);
            if (a[l].ch != a[r].ch) ans += (posr - pre[r - 1]);
            posr = pre[r - 1];
            r--;
            if (l == r) break;
        }
        // cout << ans << '\n';
        if (l == r) break;
        posr -= need;
        if (a[r].ch != a[l].ch) ans += need;
        l++;
        // cout << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}