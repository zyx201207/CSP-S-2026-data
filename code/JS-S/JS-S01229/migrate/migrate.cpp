#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e6 + 10;
#define int long long

int c, t;
int n, d;
int x[N];
int dp[N];
int fangan[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t --){
            cin >> n >> d;
            for(int i = 1; i <= n; i ++)
                cin >> x[i];
            sort(x + 1, x + 1 + n);
            int cha = x[n] - x[n - 1];
            if(cha > d|| n <= 2 || d == cha){
                cout << 0 << endl;
                continue;
            }
            int totlen = x[n] - x[1];
            int jiange = d + cha;
            if(totlen - jiange < 0){
                cout << 0 << endl;
                continue;
            }
            // cout << totlen << ' ' << jiange << ' ' << cha << endl;
            int tmp = 0;
            if((totlen - jiange) % cha != 0) tmp = 1;
            // cout << "tmp : " << tmp << endl;
            cout << (totlen - jiange) / cha  + 1 << endl;
        }
        return 0;
    }
    while(t --){
        cin >> n >> d;
        for(int i = 1; i <= n; i ++){
            cin >> x[i];
        }
        int ans = 0;
        sort(x + 1, x + 1 + n);
        for(int st = 1; st <= n; st ++){
            for(int i = 0; i <= n; i ++)
                dp[i] = 2 * 1e18 + 10;
            dp[st] = 0;
            fangan[st] = 1;
            memset(fangan, 0, sizeof fangan);
            for(int i = st; i <= n; i ++){
                for(int j = i - 1; j >= st; j --){
                    if(x[i] - x[j] > d) break;
                    if(dp[i] == dp[j] + 1)
                        fangan[i] ++;
                    else if(dp[i] > dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        fangan[i] = max(1ll, fangan[j]);
                    }
                }
            }
            for(int i = st; i <= n; i ++)
                if(fangan[i] == 2) ans ++;
            // if(st){

            //     for(int i = 1; i <= n; i ++)
            //         cout << fangan[i] << ' ';
            //     cout << endl;
            // }

        }

        cout << ans << endl;
    }
    return 0;
}
//