#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long s[200005];

char g(long long m) {
    for(int i = 1; i <= n; i++) {
        if(m <= s[i]) {
            return c[i];
        }
    }
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    long long len = 0;
    for(int i = 1; i <= n; i++)  {
        scanf("%d %c", &a[i], &c[i]);
        len += a[i];
        s[i] = s[i - 1] + a[i];
    }
    long long ans =0;
    for(long long i = 1; i <= len / 2; i++) {
        if(g(i) != g(len + 1 - i))ans++;
    }
    printf("%lld", ans);
    return 0;
}
