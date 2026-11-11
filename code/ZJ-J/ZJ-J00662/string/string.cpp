#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int st, ed;
    char c;
};
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    vector <node> a;
    a.push_back({0, 0, ' '});
    int n;
    cin >> n;
    int t = n, len = 1, midi = -1;
    while (t--) {
        int x;
        char c;
        cin >> x >> c;
        a.push_back({len, len+x-1, c});
        len += x;
    }
    len--;
    // cout << len;
    int mid = (len + 1) / 2;
    for (int v = 1; v <= n; v++) {
        auto i = a[v];
        if (i.st <= mid && mid <= i.ed) {
            midi = v;
            break;
        }
    }
    int i = 1, j = n, ll = 1, rr = len, ans = 0;
    // cout << "i\tj\tll\trr\tans\n";
    while (i <= midi && j >= midi && ll <= rr) {
        // cout << i << '\t' << j << '\t' << ll << '\t' << rr << '\t' << ans << '\n';
        // int leftl = a[i].ed - i;
        // int rightl = i - a[j].st;
        int leftl, rightl;
        if(i == midi) leftl = abs(mid-ll);
        else leftl = abs(a[i].ed - ll);
        if(j == midi) rightl = abs(rr-mid);
        else rightl = abs(rr - a[j].st);
        int moveable = min(leftl, rightl) + 1;
        ll += moveable, rr -= moveable;
        if (a[i].c != a[j].c) ans += moveable;
        if (ll > a[i].ed) i++;
        if (rr <= a[j].st) j--;
    }
    // cout << i << '\t' << j << '\t' << ll << '\t' << rr << '\t' << ans << '\n';
    cout << len << ' ' << ans;
    return 0;
}