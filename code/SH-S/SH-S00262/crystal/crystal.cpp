#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long

const ll maxn = 1e5 * 5 + 10;
ll n, m, a[maxn], k, ans, l;


int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i++){
        k = i;
        ll tmp = 0, t = 0;
        ll j = i;
        while(tmp <= m && j >= 1){
            if(tmp + a[i] - a[j] > m || j < 1) break;
            tmp += a[i] - a[j];
            t += 1;
            j -= 1;
        }
        // printf("t::%lld\n", t);
        ans = max(ans, t);
    }
    printf("%lld\n", ans);
    return 0;
}