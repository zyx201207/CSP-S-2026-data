#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

long long a[MAXN], s[MAXN];
int n;
long long m;

bool check(int x) {
    for (int i = x; i <= n; i++) {
        long long num = 0;
        num = (x - 1) * a[i] - (s[i - 1] - s[i - x]);
        if (num <= m) return true;
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}
