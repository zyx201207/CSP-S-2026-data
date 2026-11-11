#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e6 + 7;
int c, t, n, d, x[N];
bool flag = true;
bool check(int l, int r){
    for(int i = l + 1; i <= r; i++){
        if(x[i] = x[i - 1] > d) return false;
    }
    int sum = 0;
    for(int k = 0; k < r - l - 1; k++){
        if(x[l + k + 2] - x[l + k] <= d) sum++;
    }
    if(sum == 2) return true;
    return false;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 2; j <= n; j++){
                if(check(i, j)) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}