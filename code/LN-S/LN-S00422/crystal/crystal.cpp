#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int n;
long long m, sum;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int i = 0;
    while (sum < m && i <= n) {
        ++i;
        sum += ((i - 1) * (a[i] - a[i - 1]));
    }
    while (a[i + 1] == a[i] && i < n) {
        ++i;
    }
    if (sum <= m) {
        printf("%d\n", i);
    } else {
        printf("%d\n", i - 1);
    }
    return 0;
}
