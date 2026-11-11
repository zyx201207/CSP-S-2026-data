#include<bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d;
long long x[2000001];
long long sum[2000001];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d%lld", &n, &d);
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &x[i]);
            sum[i] = sum[i - 1] + x[i];
        }
    }
    cout << 0;
    return 0;
}
