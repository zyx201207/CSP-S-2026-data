#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], sum[N];
long long n, m;
bool check(long long mid, long long i){
    long long l = i - mid + 1;
    if(a[i] * mid - (sum[i] - sum[l - 1]) <= m){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("crystal.in", "r",stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
    }
    long long ans = 1;
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i ++){
        long long l = 1, r = i;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(check(mid, i)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ans = max(ans, l - 1);
    }
    printf("%lld", ans);
    return 0;
}
