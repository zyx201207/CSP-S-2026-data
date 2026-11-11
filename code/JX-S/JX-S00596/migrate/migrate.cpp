#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10, inf = 1e18;
int c, t;
int n, d;
int x[N];
int dis[310][310];
int num[310][310];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t --){
        scanf("%lld%lld", &n, &d);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                num[i][j] = 0;
                dis[i][j] = inf;
            }
        }
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &x[i]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                if(x[j] - x[i] <= d){
                    dis[i][j] = dis[j][i] = d;
                    num[i][j] = num[j][i] = 1;
                }
            }
        }
        for(int k = 1; k <= n; k ++){
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j ++){
                    int len1 = abs(x[k] - x[i]);
                    int len2 = abs(x[k] - x[j]);
                    if(len1 <= d && len2 <= d){
                        if(len1 + len2 == dis[i][j]){
                            num[i][j] ++, num[j][i] ++;
                        }
                        else if(len1 + len2 < dis[i][j]){
                            dis[i][j] = dis[j][i] = len1 + len2;
                            num[i][j] = num[j][i] = 1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(num[i][j] % 2 == 0 && num[i][j] / 2 == 2){
                    ans ++;
                }
            }
        }
        printf("%lld\n", ans / 4 - 1);
    }
    return 0;
}