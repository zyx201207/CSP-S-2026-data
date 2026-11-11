#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 0x3f;
#define endl '\n'
const int N = 2e5+5;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n <= 20){
        ll ans = INT_MIN;
        for(int i = 0; i < (1<<n); i++){
            int cnt = 0;
            ll r = (1<<26)-1;
            for(int j = 0; j < n; j++){
                if((i>>j) & 1){
                    cnt++;
                    r &= a[j];
                }
                if(cnt > m) continue;
            }
            if(cnt == m){
                ans = max(ans, r);
            }
        }
        cout << ans << endl;
    }else if(m == 1){
        ll ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }else if(m == 2){
        ll ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ans = max(ans, a[i]&a[j]);
            }
        }
        cout << ans << endl;
    }else if(m == n){
        ll ans = (1<<25) - 1;
        for(int i = 1; i <= n; i++){
            ans &= a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
