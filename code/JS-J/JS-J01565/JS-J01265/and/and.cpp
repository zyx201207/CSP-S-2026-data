#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    int ans = a[n];
    if (m == 1){
        cout << a[n];
        return 0;
    }
    if (m == n){
        for (int i = n - 1; i >= 1; i--) ans &= a[i];
        return 0;
    }
    for (int i = n - 1; i > n - m; i--) ans &= a[i];
    cout << ans;
    return 0;
}
