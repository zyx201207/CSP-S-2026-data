#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
bool cmp(int a, int b){
    return a > b;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ans = pow(2, 30) - 1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= m; i++) {
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}
