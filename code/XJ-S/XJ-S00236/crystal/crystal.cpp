#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500010;

int n;
ll m;
ll a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);

    int i = 1;
    ll sum = 0;
    ll mx = a[1];
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        int len = j - i + 1;
        sum += (a[j] - mx) * max((ll)0, (ll)len - 1);
        mx = a[j];
        
        while (i <= j && sum > m) {
            sum -= a[j] - a[i];
            i++;
        }
        
        len = j - i + 1;
        ans = max(ans, len);
    }
    printf("%d\n", ans);
    return 0;
}

/*
-----

1 4
5

-----

5 0
1 3 8 5 10

-----

5 0
1 3 3 2 9

-----

1 0
6

*/
