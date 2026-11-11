#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
int n, m;
int ans;
int a[200010], f[200010];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int k = 30; k >= 0; k--){
        int cnt(0);
        for(int i = 1; i <= n; i++){
            if(!f[i] && a[i] & (1 << k)){
                cnt++;
            }
        }

        if(cnt >= m){
            ans += (1 << k);
            for(int i = 1; i <= n; i++){
                if(!(a[i] & (1 << k))){
                    f[i] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
