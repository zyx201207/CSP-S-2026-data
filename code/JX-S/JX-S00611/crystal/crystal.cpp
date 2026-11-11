#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, ans = 0;
long long a[N], b[N], m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b+1, b+n+1);
    for (int i = 1; i < n; i++) {
        a[i] = b[i+1] - b[i];
    }
    long long mx = 0, sum = 0;
    int j = 1;
    for (int i = 1; i < n; i++) {
        while (j < n && mx <= m) {
            sum += a[j];
            mx += (j - i + 1) * a[j];
            j++;
        }
        ans = max(ans, j - i - 1);
        mx -= sum;
        sum -= a[i];
    }
    printf("%d\n", ans + 1);
    return 0;
}
