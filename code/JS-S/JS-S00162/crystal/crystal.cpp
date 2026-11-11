#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int a[N], pre[N];
int n, m, ans = 0;

bool check(int x){
    for(int i=1; i<=n; i++){
        if(i <= x) continue;
        else{
            int res = a[i] * x - (pre[i-1] - pre[i-x-1]);
            if(res <= m) return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + a[i];
    }
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans+1 << '\n';
    return 0;
}
//multi tests all delete
//be careful with Mod
//brute force!!!
//remember freopen!!!