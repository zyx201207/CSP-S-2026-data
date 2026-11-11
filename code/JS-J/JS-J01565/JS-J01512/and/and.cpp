#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool xinzhiyi = 1, xinzhier =1;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n>> m;
    int ma = 0;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
        bool xxx = 0;int f = 0;
        for(int j = 0; j <= (a[i] + 1)/ 2; j++) {
            if((int)pow(2, j) == a[i] + 1){
                xxx += 1;
                break;
            }
            
        }
        xinzhiyi *= (int)xxx;
        if(a[i] == i - 1) xinzhier *= 1;
    }
    for(int i = 1; i <= (n + 1) / 2; i++) {
        if((int)pow(2, i) == n) xinzhier *= 1;
    }
    if(m == 1) {
        cout << ma;
        return 0;
    }
    if(m == 2) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans; 
        return 0;
    } 
    if(m == n) {
        int ans = a[1];
        for(int i = 1; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == n - 1) {
        int ans = a[1], ans2 = 0;
        for(int i =1 ; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(j != i) {
                    ans *= a[j];
                }
            }
            ans2 = max(ans2, ans);
        }
        cout << ans2;
        return 0;
    }
    if(xinzhiyi) {
        sort(a + 1, a + n + 1);
        cout << a[n + 1 - m];
        return 0;
    }
    if(xinzhier && m != n - 1) {

        cout << n - m;
        return 0;
    }
    return 0; 
}