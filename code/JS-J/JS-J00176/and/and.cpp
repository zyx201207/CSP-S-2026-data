#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N], ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= m; i++){
        if(i == 1)ans = a[i];
        else ans &= a[i];
    }
    cout << ans;
    return 0;
}
