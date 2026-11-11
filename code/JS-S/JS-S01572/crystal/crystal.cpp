#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, maxn, ans;
long long a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    if (n == 0){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    maxn = 1, ans = 1;
    int zd = 1;
    for (int i = 2; i <= n; i++){
        while (zd <= i && ans * (a[i] - a[i - 1]) > m){
            m += a[i - 1] - a[zd];
            ans--;
            zd++;
        }
        if (ans * (a[i] - a[i - 1]) <= m){
            m -= ans * (a[i] - a[i - 1]);
            ans++;
            maxn = max(maxn, ans);
        }
    }
    cout << maxn;
    return 0;
}
