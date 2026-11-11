#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e6 + 5;
const int M = 5e3 + 5;
int c, T, n, d, ans, pos, cnt, x[N], pre[N], to[M][M];
vector<int> v;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> T;

    while(T --) {
        ans = 0;

        cin >> n >> d;
        for(int i = 1 ; i <= n ; ++ i)
            cin >> x[i];
        
        for(int i = 1 ; i <= n ; ++ i) {
            to[i][1] = upper_bound(x + i, x + 1 + n, x[i] + d) - x - 1;
            to[i][1] = min(to[i][1], n);
        }

        // for(int i = 1 ; i <= n ; ++ i) {
        //     cout << to[i][1] << ' ';
        // }
        // cout << '\n';

        for(int i = 1 ; i <= n ; ++ i) {
            for(int j = 2 ; j <= n ; ++ j) {
                if(to[i][j - 1] != n) to[i][j] = to[to[i][j - 1]][1];
                else break ;
            }
        }

        for(int i = 1 ; i <= n ; ++ i) {
            for(int j = i + 1 ; j <= n ; ++ j) {
                cnt = 0;
                pos = i;

                while(pos < j) {
                    pos = to[pos][1];

                    if(pos < j && pos == to[pos][1]) {
                        cnt = 2;
                        break ;
                    }

                    if(pos < j) v.pb(pos);
                }

                for(int k = 0 ; k < (int)v.size() ; ++ k) {
                    if(to[v[k] - 1][v.size() - k] >= j) ++ cnt;
                    if(to[v[k] - 2][v.size() - k] >= j) ++ cnt;

                    if(cnt > 1) break ;
                }

                // for(auto k : v)
                //     cout << k << ' ';
                // cout << '\n';

                v.clear();

                // cout << "cnt:" << cnt << '\n';

                if(cnt == 1) ++ ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}