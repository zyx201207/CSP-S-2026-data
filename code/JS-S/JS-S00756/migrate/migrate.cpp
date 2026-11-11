#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5010 + 10, INF = 9e18;
int c, T;
int n, d;
int a[N];
int ans[N], cnt[N], pos[N], flag[N];
void solve(){
    int sum(0);
    rep(i, n) cin >> a[i];
    rep(k, n){
        memset(flag, 0, sizeof(flag));
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        memset(pos, 0, sizeof(pos));
        int l(k), now(0);
        for(int i = k + 1; i <= n; i++){
            while(a[i] - a[l] > d){
                l++;
            }
            if(l == i){
                //cout << 0 << ' ' << 0 << '\n';
                break;
            }
            ans[i] = ans[l] + 1;
            cnt[ans[i]]++;
            pos[i] = cnt[ans[i]];
            if(cnt[ans[l]] == pos[l] + 1){
                if(flag[l] == 0 && flag[l + 1] == 0){
                    sum++;
                    flag[i] = 1;
                }
                else{
                    flag[i] = 2;
                }
            }
            else if(cnt[ans[l]] == pos[l]){
                flag[i] = flag[l];
                if(flag[l] == 1) sum++;
            }
            else{
                flag[i] = 2;
            }
            //cout << ans[i] << ' ' << pos[i] << ' ' << flag[i] << '\n';
        }
        //cout << '\n';
    }
    cout << sum << '\n';
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        solve();
    }
    return 0;
}
