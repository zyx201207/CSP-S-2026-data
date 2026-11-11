#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c,t,n,d,a[N],ans[N],cnt;

void dfs(int u,int v,int stp) {
    // cout << u << " " << v << " "<< stp << "\n";
    if(u == v) {
        ans[stp]++;
        return;
    }
    for(int i = 1;i <= n ; i++) {
        if(a[u + i] - a[u] > d || u + i > v) break;
        dfs(u + i,v,stp + 1);
    }
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--) {
        int cnt = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if(n <= 9) {
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    for(int k = 1; k<= n; k++) {
                        ans[k] = 0;
                    }
                    dfs(i,j,0);
                    for(int k = 1; k <= a[j] - a[i]; k++) {
                        if(ans[k] == 2) {
                            // cout << i << " " << j << endl;
                            cnt++;
                            break;
                        }
                        if(ans[k]) break;
                    }
                }
            }
            cout << cnt << "\n";
        }
        else{
            int gb = a[2] - a[1];
            int x = 2 * d - gb;
            if(x % gb == 0 && x / gb == 3) {
                cout << n - x + 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/