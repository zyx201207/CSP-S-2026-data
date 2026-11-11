#include <bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
ll cs, op;
ll c[N]; // all 1 based
ll lpt=0, rpt=1; // rpt is target crystal
ll ans = 0;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &cs, &op);
    for (int i=1; i<=cs; i++) {
        scanf("%lld", &c[i]);
    }
    sort(c+1, c+cs+1);
    ll sum = 0;
    sum += c[1];
    if (op==0) goto out;
    do {
        sum -= (c[rpt]-c[lpt]);
        lpt++;
        if (sum <= op) {
            while (sum<=op) {
                rpt++;
                if (rpt == cs) {
                    sum += (rpt-lpt)*(c[rpt]-c[rpt-1]);
                    rpt -= sum>op ? 1 : 0;
                    ans = rpt-lpt+1 > ans ? rpt-lpt+1 : ans;
                    goto out;
                }
                sum += (rpt-lpt)*(c[rpt]-c[rpt-1]);
                ans = rpt-lpt > ans ? rpt-lpt : ans;
            }
        } else {
            continue;
        }
    } while(true);

    out:
    printf("%lld", ans);
    return 0;
}
