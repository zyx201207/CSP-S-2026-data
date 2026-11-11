#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
const long long MAXN = 1.1e12, MINN = -1.1e12;
int n;
long long num, m, ans, a[N], sum[N];
void solve(long long l, long long r, int st){
    if(l >= r) return;
    long long mid = l + (r - l >> 1) + 1, pos = upper_bound(a + 1, a + n + 1, mid) - a - 1;
    if(pos < st) return;
    if(mid * (pos - st + 1) - sum[pos] + sum[st - 1] <= m) ans = max(pos - st + 1, ans), solve(mid, r, st);
    else solve(l, mid - 1, st);
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 1 ; i <= n ; ++i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + a[i];
    for(int i = 1 ; i <= n ; ++i) solve(MINN, MAXN, i);
    printf("%d\n", ans);
    return 0;
}
