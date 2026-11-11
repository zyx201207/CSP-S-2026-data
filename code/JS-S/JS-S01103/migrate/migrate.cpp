#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 307, Inf = 1e18;
ll c, T, ans, n, d;
ll f[N][N], x[N], cnt[N][N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d, ans = 0;
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = Inf, cnt[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(x[j] - x[i] <= d) f[i][j] = 1, cnt[i][j] = 1;
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    ll tmp = f[i][k]+f[k][j];
                    if(f[i][j] > tmp){
                        f[i][j] = tmp, cnt[i][j] = cnt[i][k]*cnt[k][j];
                    } else if(f[i][j] == tmp) cnt[i][j]+=cnt[i][k]*cnt[k][j];
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+3; j <= n; j++){
                if(f[i][j] != Inf && cnt[i][j] == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
