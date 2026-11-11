#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int, int> a;
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <=n ; i ++){
        cin >> a[i];
    }
    if(n <= 2000){
        if(m == 1){
            int maxn = 0;
            for(int i = 1; i <= n; i ++){
                maxn = max(maxn, a[i]);
            }
            cout << maxn;
        }
        else if(m == n){
            int ans = 0;
            for(int i = 1; i <= n; i ++){
                ans &= a[i];
            }
            cout << ans;
        }
        else if(m == 2){
            int maxn = 0;
            for(int i = 1; i <= n; i ++){
                for(int j = i+1; j <= n; j ++){
                    maxn = max(maxn, a[i]&a[j]);
                }
            }
            cout << maxn;
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
