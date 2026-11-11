#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    bool flag = 1;
    int mx = 0, sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        if(a[i] != i - 1){
            flag = 0;
        }
        if(i == 1){
            sum = a[i];
        }else{
            sum = (sum & a[i]);
        }
    }
    if(m == 1){
        cout << mx << '\n';
        return 0;
    }
    if(m == n){
        cout << sum << '\n';
        return 0;
    }
    if(m == 2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j){
                    continue;
                }
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans << '\n';
        return 0;
    }
    if(flag){
        int ans = a[n];
        for(int i = n - 1;i >= n - m + 1;i--){
            ans = (ans & a[i]);
        }
        cout << ans << '\n';
        return 0;
    }
    sort(a + 1, a + n + 1);
    cout << a[m] << '\n';
    return 0;
}
