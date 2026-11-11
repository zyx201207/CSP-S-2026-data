#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
bool cmp(int a, int b){
    return a < b;
}
int s[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    s[1] = 0;
    for(int i = 2;i <= n;i++){
        s[i] = a[i] - a[i - 1];
    }
    int l = 1, r = 1, cnt = 0, tot = 0, ans = 0;
    while(l <= r && r <= n){
        while(cnt <= m && r <= n){
            r++;
            cnt += s[r] * (r - l);
            tot += s[r];
        }
        if(cnt >= m){
            ans = max(ans, r - l);
        }
        tot -= s[l];
        l++;
        cnt -= tot;
    }
    ans = max(ans, r - l + 1);
    cout << ans << '\n';
    return 0;
}
