#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005], m;
bool check(long long x){
    int le, ri = upper_bound(a+1, a+n+1, x)-a-1;
    long long sum = 0;
    for(le = 1; le <= ri; le++){
        sum += x-a[le];
    }
    return sum <= m;
}
long long bs(long long l, long long r){
    if(l > r) return r;
    long long mid = l+r >> 1;
    if(check(mid)) return bs(mid+1, r);
    else return bs(l, mid-1);
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    long long maxn = bs(-1e12, 1e12);
    cout << upper_bound(a+1, a+n+1, maxn)-a-1;
    return 0;
}
