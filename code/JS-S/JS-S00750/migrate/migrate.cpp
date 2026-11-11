#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000010;
int x[N];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);

    int c, t;
    cin >> c >> t;
    while (t--){
        int n, d;
        cin >> n >> d;
        for (int i=1; i<=n; i++){
            cin >> x[i];
        }
        
        int ans = 0;
        // cout << 111111<< endl;
        for (int i=1; i<=n; i++){
            for (int j=i+1; j<=n; j++){
                queue <pair<int, int> > q;
                int mindis = 0x3f3f3f3f3f3f3f3f;
                int cnt = 0;
                q.push({i, 0});
                while (!q.empty()){
                    pair <int, int> tmp = q.front();
                    q.pop();
                    int pos = tmp.first, dis = tmp.second;
                    // cout << pos << endl;
                    if (pos == j){
                        if (mindis == 0x3f3f3f3f3f3f3f3f){
                            mindis = dis;
                            // printf("i:%d, j:%d, dis:%d\n", i, j, mindis);
                        }
                        if (dis == mindis){
                            cnt++;
                        }
                        if (cnt > 2) break;
                    }
                    // printf("i:%d, j:%d, pos:%d\n", i, j, pos);
                    for (int p = pos+1; x[p] - x[pos] <= d && p <= j; p++){
                        if (dis <= mindis) q.push({p, dis+1});
                        // printf("%d -> %d, dis:%d, inqueue:%d\n", pos, p, dis+1, q.size());
                    }
                    // cout << "111";
                }
                // cout << cnt << endl;
                if (cnt == 2) ans++;
                // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        }

        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}