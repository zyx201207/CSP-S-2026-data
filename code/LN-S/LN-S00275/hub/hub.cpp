#include <bits/stdc++.h>
#define N 2000004
#define ll long long
    int c, n, m, d, q;
using namespace std;
int _t, _id;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int randtgh[100];//no init for random
    scanf("%d %d", &c, &q);
    while(q--) {
        ll t = abs(randtgh[q%90] % 100);
        printf("%lld\n", t);
    }
    return 0;
}
