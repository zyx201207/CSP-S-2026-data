# include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, z, x[2000005];
int main (){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if (c == 11 || c == 12){
        while (t--){
            cin >> n >> d;
            for (int i = 1; i <= n; i++){
                cin >> x[i];
                z = x[i] - x[i - 1];
            }
            if (z > d){
                cout << 0;
            }
            long long tmp = d / z;
            long long tmp2 = tmp * z;
            long long ans = (tmp - 1) * (n - (tmp * 2 - 1));
            cout << ans << "\n";
        }
    }
    return 0;
}
