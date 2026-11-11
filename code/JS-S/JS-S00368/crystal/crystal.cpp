#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10 , INF = 1e18 , mod = 1e9 + 7;
int a[MAXN] , d[MAXN] , sum[MAXN];
int n , m;
int calc(int l , int r){
    int res = 0;
    for(int i = l + 1 ; i <= r ; ++i){
        res += d[i] * (i - l);
    }
    return res;
}
bool check(int x){
    int res = calc(1 , x);
    int minn = res;
    for(int l = 2 ; l + x - 1 <= n ; ++l){
        int r = l + x - 1;
        res = res - (sum[r] - sum[l - 1]) + d[r] * x;
        minn = min(minn , res);
    }
    return (minn <= m);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 2 ; i <= n ; ++i){
        d[i] = a[i] - a[i - 1];
    }
    for(int i = 2 ; i <= n ; ++i){
        sum[i] = sum[i - 1] + d[i];
    }
    int l = 1 , r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l;
    return 0;
}
