#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[200005];
ll s, ans;
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %c", &a[i], &c[i]), s += a[i];
    int r = n;
    ll p1 = 0, p2 = s + 1;
    for (int i = 1; ; i++) {
        p1 += a[i];
        if (p1 <= s / 2) {
            ll x = p1 - (s - p2 + 1);
            while (a[r] < x) {
                x -= a[r];
                if (c[i] != c[r])
                    ans += a[r];
                --r;
            }
            a[r] -= x;
            if (c[i] != c[r])
            	ans += x;
            p2 = s - p1 + 1;
            if (p1 == s / 2)
            	break;
        } else {
            int x = s - p1 + a[i] - p1;
            if (s & 1)
                ++x;
			while (a[r] < x) {
                x -= a[r];
                if (c[i] != c[r])
                    ans += a[r];
                --r;
            }
            a[r] -= x;
            if (c[i] != c[r])
            	ans += x;
            break;
        }
    }
    printf("%lld\n", ans);
}

