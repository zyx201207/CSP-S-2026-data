#include<bits/stdc++.h>
#define FILE "crystal"
using namespace std;
using i64 = long long;

namespace FakeWilson {
const int N = 5e5 + 5;
i64 a[N];

signed main() {
    int n; i64 m;
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + 1 + n);
    int p = 1, ans = 0; i64 sum = 0; 
    for(int i = 1; i <= n; i++) {
        if(i) sum += (a[i] - a[i - 1]) * (i - p);
        while(p < i && sum > m) {
            sum -= a[i] - a[p], p++;
        }
        ans = max(ans, i - p + 1);
        // cout << "QWQ" << i << " " << p << endl;
    }
    printf("%d", ans);
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}
