#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

struct node {
    int x;
    char c;
};

node a[N];

signed main() {

     freopen("string.in", "r", stdin);
     freopen("string.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
    }

    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int c = abs(a[l].x - a[r].x);
        if (a[l].c == a[r].c) {
            if (a[l].x < a[r].x) {
                a[r].x -= a[l].x;
                l++;
                continue;
            } else if (a[l].x > a[r].x) {
                a[l].x -= a[r].x;
                r--;
                continue;
            } else {
                l++, r--;
                continue;
            }
        } else {
            if (a[l].x < a[r].x) {
                ans += a[l].x;
                a[r].x -= a[l].x;
                l++;
                continue;
            } else if (a[l].x > a[r].x) {
                ans += a[r].x;
                a[l].x -= a[r].x;
                r--;
                continue;
            } else {
                ans += a[l].x;
                l++, r--;
                continue;
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}

/*

aabbc

2 a
2 b
1 c



*/
