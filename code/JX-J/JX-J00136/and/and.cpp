#include<bits/stdc++.h>
using namespace std;

long long aa(int n, int m) {
    long long a[200001], ma = -1;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        ma = max(ma, a[i]);
    return ma;
}

long long b(int n, int m) {
    long long a[200001], ma = -1;
    for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        for (int  j = i + 1; j <= n; j++) {
            ma = max(ma, a[i] & a[j]);
        }
    }
    return ma;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    if (m == 1) {
        printf("%d", aa(n, m));
        return 0;
    }
    if (m == 2) {
        printf("%d", b(n, m));
        return 0;
    }
    long long ma;
    long long a[200001];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ma = a[1];
    for (int i = 2; i <= n; i++)
        ma = ma & a[i];
    printf("%lld", ma);
    return 0;
}
