#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 2;j <= n;j++) {
                for(int k = i + 1;k <= j - 1;k++) {
                    if(x[j] - x[k] <= d && x[k] - x[i] <= d) cnt++;
                }
            }
        cout << cnt / 4 << endl;
    }
    return 0;
}
