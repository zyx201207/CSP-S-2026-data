#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+100;
int n;
ll m, a[N], sum[N];
ll cal_sum(int l, int r){
    return sum[r] - sum[l-1];
}
bool check(int v){
    for(int i = 1; i + v - 1 <= n; i++){
        int st = i, ed = i + v - 1;
        ll tot = cal_sum(st, ed);
        ll diff = a[ed] * v - tot;
        if (diff <= m) return true;
    }
    return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
    }
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}
