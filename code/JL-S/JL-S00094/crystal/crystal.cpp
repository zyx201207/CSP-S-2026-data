#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long p[500010];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++){
        p[i] = p[i-1] + a[i];
    }
    int l = 1, r = n;
    while( l < r - 1 ){
        int mid = (l + r) / 2;
        long long cnt = 1e18;
        for(int i=mid; i<=n; i++){
            cnt = min(cnt, a[i]*mid - (p[i] - p[i-mid]));
        }
        if( cnt > m ) r = mid - 1;
        else l = mid;
    }
    printf("%d", l);
    return 0;
}
