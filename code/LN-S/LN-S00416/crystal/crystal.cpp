#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
int a[500010];
int s[500010];
int ans = -1e18;
bool check(int x) {
    for(int i = 1 ; i + x - 1 <= n ; i ++) {
        if(s[i + x - 1] - s[i] <= m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    sort(a + 1 , a + 1 + n);
    s[1] = 0;
    for(int i = 2 ; i <= n ; i ++) {
        s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
    }
    int l = 1 , r = n , mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
