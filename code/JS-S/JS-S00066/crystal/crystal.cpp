#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500000 + 50;
int n, m;
int a[MAXN], pre[MAXN];
bool check(int x){
    for(int i = x; i <= n; i++){
        int sum = pre[i - 1] - pre[i - x], t = a[i] * (x - 1);
        if((t - sum) <= m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl;
    return 0;
}
