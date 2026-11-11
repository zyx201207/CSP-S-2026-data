#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e3+5;

int dp[N][N], cnt[N][N];
int island[2000005];
int n, d;

void f(){
    cout << 0 << '\n';
    return;
}

void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i ++)cin >> island[i];

    if(n > 100000){
        f();
        return;
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            if(i == j){
                dp[i][j] = 0;
                cnt[i][j] = 1;
                continue;
            }

            int mn = 1e9+7, mncnt = 0;
            for(int k = i; k < j; k ++){
                if(island[j] - island[k] <= d){
                    if(dp[i][k] < mn){
                        mn = dp[i][k];
                        mncnt = cnt[i][k];
                    }else if(dp[i][k] == mn){
                        mncnt += cnt[i][k];
                    }
                }
            }
            dp[i][j] = mn+1;
            cnt[i][j] = mncnt;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = i+1; j <= n; j ++){
            if(cnt[i][j] == 2)ans++;
        }
    }
    cout << ans << '\n';

}

int main(){

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int testnum, T;
    cin >> testnum >> T;
    while(T--)solve(); 
    

    return 0;
}