/* It will be my last year as an OIer
This year I am JS-S00027
Now examination starting*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[500005];
ll cnt, ans=1, k=1, pos;

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld %lld", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    for(int i=1; i<n; i++) {
        cnt += k*(a[i] - a[i-1]);
        k++;
        while(cnt > m) {
            k--;
            cnt -= (a[i] - a[pos]);
            pos++;
        }
        ans = max(ans, k);
    }
    printf("%lld", ans);
    return 0;
}

// 10 minutes miaole?
// 100pts
