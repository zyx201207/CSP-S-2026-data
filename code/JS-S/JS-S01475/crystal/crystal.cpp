#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
long long m, a[500005], sum[500005];
int check(long long x, int j) {
    int total = 0;
    int l = 1, r = j;
    while(l <= r) {
        int mid = (l + r) / 2;
        int nowtotal = (j - mid + 1);
        int nowsum = sum[j] - sum[mid - 1];
        if((long long)nowtotal * x - nowsum <= m) {
            total = nowtotal;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return total;
}
int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf(" %d %lld", &n, &m);

    for (int i = 1; i <= n; i ++) {
        scanf(" %lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 2; i --) {
        if(i <= ans)
            break;
        int now = check(a[i], i - 1);
        ans = max(ans, now);
    }
    printf("%d", ans + 1);
    return 0;
}
