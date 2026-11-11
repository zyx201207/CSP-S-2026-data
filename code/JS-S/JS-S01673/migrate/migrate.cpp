#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
ll c, t;
ll n, m;
ll g[N];
ll dp[N][N];
ll sum = 0;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t -- ){
        sum = 0;
        cin >> n >> m;
        ll len = m + m - 1;
        for(int i = 1; i <= n; i ++ ){
            cin >> g[i];
        }
        for(int i = 2; i <= n; i ++ ){
            for(int j = 1; j < i; j ++ ){
                if(g[i] - g[i - 1] > m) continue;
                if(g[i] - g[j] < len) continue;
                if((g[i] - g[j] - len) % m == 0) sum ++ ;
            }
        }
        cout << sum << endl;
    }


    return 0;
}
