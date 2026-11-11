#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 200010;

struct data {
    int cnt;
    char s[5];
};

data a[MAXN];
int n, l, r, mi;
long long ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d%s", &a[i].cnt, a[i].s);
    }
    ans = 0;
    l = 1; r = n;
    while (l < r) {
        if (a[l].cnt < a[r].cnt) mi = a[l].cnt;
        else mi = a[r].cnt;
        if (a[l].s[0] != a[r].s[0]) ans = ans + mi;
        a[l].cnt -= mi;
        if (a[l].cnt <= 0) l++;
        a[r].cnt -= mi;
        if (a[r].cnt <= 0) r--;
    }
    printf("%lld", ans);
    return 0;
}
