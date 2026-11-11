#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500005], moni[500005], haxi[100005], ans[100005];

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++) {
        int cnt = 0;
        for(int j = 1 ; j <= m ; j++) {
            haxi[j] = -1;
        }
        for(int j = i ; j <= n ; j++) {
            if(haxi[a[j]] != -1) {
                for(int k = haxi[a[j]] + 1; k <= cnt ; k++)
                    haxi[a[k]] = -1;
                cnt = haxi[a[j]];
            } else {
                ++cnt;
            }
            moni[cnt] = a[j];
            haxi[a[j]] = cnt;
        }
        for(int j = 1 ; j <= cnt ; j++) {
            ans[moni[j]]++;
        }
    }
    for(int i = 1 ; i <= m ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
