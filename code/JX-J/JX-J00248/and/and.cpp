#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], b[200005], ans;
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int k = 30 - 1; k >= 0; k --){
        int sum = 0;
        for (int i = 1; i <= n; i ++){
            if (!b[i]){
                if (a[i] & (1 << k)){
                    sum ++;
                }
            }
        }
        if (sum < m){
            continue;
        }
        else {
            for (int i = 1; i <= n; i ++){
                if (!b[i]){
                    if ((a[i] & (1 << k)) == 0){
                        b[i] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        if (!b[i]){
            if (ans == 0) ans = a[i];
            else ans &= a[i];
        }
    }
    cout << ans << endl;

    return 0;
}
