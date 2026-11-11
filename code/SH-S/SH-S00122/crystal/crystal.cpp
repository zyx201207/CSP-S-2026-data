#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500010;
int n,m,a[N];
double aver;
int maxn,goal;   // goal表示最后加出来的众数
int sum, cnt;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
        aver += double(a[i]) / double(n);
    }
    sort(a+1, a+n+1);

    maxn = ceil(aver + double(m) / double(n)) - 1;
    auto pos = lower_bound(a+1, a+n+1, maxn);  // 下标即pos-a
    if (*pos > maxn) {
        --pos;
    }
    goal = *pos;

        // printf("pos=%ld goal=%lld a[pos]=%lld\n",pos-a,goal,a[pos-a]);

    for (int i=1; i<=n; ++i) {
        cnt += a[i] == goal;
    }

    for (int i=(pos-a)-1; i>=1; --i) {
        sum += goal - a[i];
        cnt += goal - a[i] != 0;
                // printf("i=%lld sum=%lld\n", i, sum);
        if (sum == m) {
            printf("%lld\n", cnt);
            return 0;
        } else if (sum > m) {
            sum -= goal - a[i];
            cnt -= goal - a[i] != 0;
                // printf("cnt=%lld\n",cnt);
            for (int j=(pos-a); j<=n; ++j) {
                int k = (a[j] - goal) * cnt;
                    // printf("j=%lld sum=%lld k=%lld\n", j, sum,k);
                if (k and k <= m - sum) {
                    ++cnt, sum += k;
                } else {
                    break;
                }
            }
            printf("%lld\n", cnt);
            return 0;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}