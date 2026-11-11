#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 500010;

long long a[MAXN], sum[MAXN], m;
int n, l, r, mid, ans;

bool check(int x) {
    long long s1, s2;
    for (int i=x; i<=n; i++) {
        s1 = a[i] * x;
        s2 = sum[i] - sum[i-x];
        if (s1 - s2 <= m) return true;
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    sum[0] = 0;
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
    l = 1; r = n;
    while (l <= r) {
        mid = (l+r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%d", ans);
    return 0;
}
