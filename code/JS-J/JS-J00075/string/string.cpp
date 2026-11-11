#include <bits/stdc++.h>
using namespace std;

int n;
struct Info{
    int v;
    char c;
}a[200005];
long long ans[30];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%d", &n);
    char enter;
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d%c%c", &a[i].v, &enter, &a[i].c);
        sum += a[i].v;
    }
    long long mid = sum / 2, ntot = 0, pos, m;
    for (int i = 1; i <= n; i++){
        if (ntot + a[i].v >= mid)
                pos = i;
        else
            ntot += a[i].v;
    }
    m = ntot + a[pos].v;
    for (int i = 1; i < pos; i++)
        ans[a[i].c - 'a'] = a[i].v;
    ans[a[pos].c] = mid - ntot;
    ans[a[pos].c] = ans[a[pos].c] - m + mid;
    for (int i = pos + 1; i <= n; i++)
        ans[a[i].c - 'a'] -= a[i].v;
    long long tot = 0;
    for (int i = 0; i < 27; i++)
        if (ans[i] > 0)
            tot += ans[i];
    printf("%lld\n", tot);
    return 0;
}
