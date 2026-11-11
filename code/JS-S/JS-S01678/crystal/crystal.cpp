#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 0x3f;
#define mst(x, y) memset(x, y, sizeof(x))
#define endl '\n'
const int N = 5e5+5;
ll a[N], b[N], f[N][30], p[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        //f[0][i] = a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        b[i] = b[i-1]+a[i];
    }
    if(n > 5000){
        /*ll ans = LLONG_MIN;
        for(int i = 1; i <= n; i++){
            if(i<= ans) continue;
            if(a[i]*i - b[i] <= m){
                ans = max(ans, i);
            }
        }*/
        //cout << ans;
        int l = 0, r = n;
        while(l < r){
            int mid = l+r+1>>1;
            bool f = false;
            for(int i = 1; i+mid-1 <= n; i++){
                if(a[i+mid-1]*mid - (b[i+mid-1]-b[i-1]) <= m){
                    f = true;
                }
            }
            if(f) l = mid;
            else r = mid-1;
        }
        cout << l;
    }else{
        ll ans = LLONG_MIN;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                auto len = j-i+1;
                if(len <= ans) continue;
                if(a[j]*len - (b[j] - b[i-1]) <= m){
                    ans = max(ans, len);
                }
            }
        }
        cout << ans;
    }
    return 0;
}
