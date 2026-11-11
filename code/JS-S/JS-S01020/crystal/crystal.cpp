# include <bits/stdc++.h>
using namespace std;
long long n, m, ans, z, lz, a[500005], qz[500005];
int main (){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        qz[i] = qz[i - 1] + a[i];
    }
    ans = 1;
    lz = 1;
    for (int i = 2; i <= n; i++){
        z += (a[i] - a[i - 1]) * (i - lz);
        if (z > m){
            while (lz < i){
                z -= (a[i] - a[lz]);
                lz++;
                if (z <= m){
                    break;
                }
            }
        }
        ans = max(ans, i - lz + 1);
    }
    cout << ans;
    return 0;
}
