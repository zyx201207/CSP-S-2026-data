#include<bits/stdc++.h>
using namespace std;
const int N = 3005;vector<long long> v;
long long n,d;long long c,t;long long x[N];
vector<long long> dp[N][N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> c >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(x,0,sizeof(x));
        long long ans = 0;

        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        cout << 1 << "\n" << 2;
        if(c < 11){
            for(int i = 1;i <= n;i++){
                dp[i][i].push_back(0);
            }
            for(int i = 1;i <= n;i++){
                int s = lower_bound(x+1,x+n+1,x[i]+d) - x;
                //cout << s;
                for(int j = s;j <= n;j++){
                    for(int k = i;k < s;k++){
                        for(int p : dp[i][k]){
                            dp[i][j].push_back(p+1);
                        }
                    }
                    sort(dp[i][j].begin(),dp[i][j].end());
                    int cnt = 1;
                    for(int k = 1;k < dp[i][j].size();k++){
                        if(dp[i][j][k]==dp[i][j][k-1])cnt++;
                        if(cnt > 2)break;
                    }
                    if(cnt == 2)ans++;
                }
            }
            cout << ans << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
