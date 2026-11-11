#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long n, m;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    long long ans = 1;
    for(long long i = 2; i <= n; i++) {
        long long cost = (i - 1) * (long long)(a[i]) - s[i - 1];
        if(cost <= m) {
            ans = max(i, ans);
        } else {
            break;
        }
    }
    cout << ans;
    return 0;
}
