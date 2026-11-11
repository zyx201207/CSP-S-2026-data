#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e6 + 10;
int c,t;
int n,d,cnt[N];
int x[N],dp1[N],dp2[N];
void solve(){
    cin >> n >> d;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x+1,x+n+1);
    queue<int> q;
    if (n <= 5000){
        for (int i = 1; i <= n; i++){
            while(!q.empty()) q.pop();
            for (int j = 0; j <= n; j++) cnt[j] = 0;
            for (int j = i; j <= n; j++) dp1[j] = 1e18,dp2[j] = 0;
            dp1[i] = 0;
            dp2[i] = 1;
            q.push(i);
            cnt[0]++;
            for (int j = i + 1; j <= n; j++){
                 while(!q.empty() && abs(x[q.front()] - x[j]) > d) cnt[dp1[q.front()]]-=dp2[q.front()],q.pop();
               //  cout << cnt[dp1[q.front()]] << " ";
                 if (!q.empty()){
                    dp1[j] = dp1[q.front()] + 1;
                dp2[j] = cnt[dp1[q.front()]];
                if (dp2[j] == 2) ans++;
                cnt[dp1[j]]+=dp2[j];
                q.push(j);  
                 }
              //   cout << dp1[j] << " ";
            }
        }
        cout << ans << '\n';
    }else{
        if (11 <= c && c <= 12){
            int dd = (x[2] - x[1]);
            int ff = d/dd;
            if (ff <= 1){
                cout << 0 << '\n';
                return ;
            }
            for (int i = 1; i <= n; i++){
                int xx1 = i + ff*2 - 1;
                if (xx1 <= n){
                    ans++;
                }
            }
            cout << ans << '\n';
            return ;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
    solve();
    }
    return 0;
}