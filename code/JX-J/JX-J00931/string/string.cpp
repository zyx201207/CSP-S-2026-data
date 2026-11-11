#include <iostream>
#include <cstdio>
using namespace std;
#define int long long

struct Node {
    int a;
    char ch;
} a[200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int cur = 0;
    while (n--) {
        int x;
        char ch;
        cin >> x >> ch;
        if (ch == a[cur].ch) a[cur].a += x;
        else a[++cur] = { x, ch };
    }
    int l = 1;
    int r = cur;
    int cnt = 0;
    while (l < r) {
        if (a[l].ch != a[r].ch) cnt += min(a[l].a, a[r].a);
        if (a[l].a > a[r].a) a[l].a -= a[r].a, r--;
        else if (a[l].a < a[r].a) a[r].a -= a[l].a, l++;
        else l++, r--;
    }
    cout << cnt;

    return 0;
}
