#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, sum;
int a[200005];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (m == 1){
        cout << a[n];
        return 0;
    }
    if (m == n){
        sum = a[1];
        for (int i = 2; i <= n; i++){
            sum &= a[i];
        }
        cout << sum;
        return 0;
    }
    ans = a[n - m + 1];
    cout << a[n - m + 1] << endl;
    for (int i = n - m + 2; i <= n; i++){
        ans &= a[i];
        cout << a[i] << endl;
    }
    cout << ans;
    return 0;
}
