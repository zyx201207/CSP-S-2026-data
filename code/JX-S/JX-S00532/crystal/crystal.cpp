#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 5e5 + 5;
int n, l, r, ans;
ll m, a[maxn], sum[maxn];
bool check(int x){
    for(int i = x; i <= n;i++){
        ll res = a[i] * x - (sum[i] - sum[i - x]);
        if(res <= m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    l = 1, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
