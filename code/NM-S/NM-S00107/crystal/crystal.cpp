#include<bits/stdc++.h>

using namespace std;

long long n, m, a[500005], u = 0;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        long long ans = 0;
        for (long long j = i; j <= n; j++) {
            if (i == n)
                continue;
            else {
                if (a[j] >= 0 && j != i)
                    ans += a[j];
                if (a[j] <= 0 && j != i)
                    ans += abs(a[j]), u++;
                if (abs(j * a[j] - a[j] - ans - u * a[j]) >= 0 && abs(j * a[j] - a[j] - ans - u * a[j] <= m)) {
                    sum = max(sum, j - i + 1);
                }
            }
        }
        u = 0;
   }
   for (long long i = 1; i <= n; i++) {
        long long ans = 0;
        for (long long j = 1; j <= i; j++) {
            if (i == 1)
                continue;
            else {
                if (a[j] >= 0 && j != i)
                    ans += a[j];
                if (a[j] <= 0 && j != i)
                    ans += abs(a[j]), u++;
                if (abs(j * a[j] - a[j] - ans - u * a[j]) >= 0 && abs(j * a[j] - a[j] - ans - u * a[j] <= m)) {
                    sum = max(sum, j - i + 1);
                }
            }
        }
        u = 0;
    }
    printf("%lld\n", sum);
    return 0;
}
