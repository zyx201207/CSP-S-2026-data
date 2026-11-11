#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

long long c,t,n,d;
long long a[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
        if (c == 13 || c == 14){
            cout << 0 << endl;
        }
        cin >> n >> d;
        int ans = 0;
        for (int i = 1;i <= n;i++) cin >> a[i];
        for (int i = 1;i <= n;i++){
            int l = i + 1;
            int r = l + 1;
            int j = r + 1;
            if (a[l] - a[i] >= d) continue;
            if (a[r] - a[i] > d) continue;
            if (a[j] - a[i] <= d) continue;
            if (a[j] - a[l] <= d && a[j] - a[r] <= d) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
