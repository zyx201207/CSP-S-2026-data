#include <bits/stdc++.h>
#define N 2000004
#define ll long long
using namespace std;
int _t, _id;
int main() {
    freopen("migrate1.in", "r", stdin);
    freopen("migrate1.out", "w", stdout);
    scanf("%d %d", &_id, &_t);
    while(_t--) {
    ll n=0;
    ll t=0;
    ll maxdst=0;
    scanf("%lld %lld", &n, &maxdst);
    ll max=0, min=0;
    scanf("%lld", &min);
    for (int i=1; i<n-1; i++) {scanf("%lld", &t);}
    scanf("%lld", &max);
    t = max - min - 2;
    printf("%lld", t);
    printf("\n");
    }
    return 0;
}
