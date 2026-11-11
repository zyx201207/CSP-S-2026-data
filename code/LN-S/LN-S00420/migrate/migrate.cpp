#include<bits/stdc++.h>
using namespace std;
const int N = 5005 + 5;
int C, T, n, ans;
long long d, x[N], dis[N][N], num[N][N];
int main(){
    //freopen("migrate3.in", "r", stdin);
    scanf("%d%d", &C, &T);
    while(T--){
        ans = 0;
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) dis[i][j] = 1e18, num[i][j] = 1;
        for(int i = 1; i <= n; i++){
            dis[i][i] = 0;
            for(int j = i+1; j <= n; j++){
                if(x[j] - x[i] <= d) dis[i][j] = 1;
            }
        }
        for(int r = 1; r <= n; r++){
            for(int l = r-1; l >= 1; l--){
                for(int k = l+1; k < r; k++){
                    if(dis[l][r] > dis[l][k] + dis[k][r]){
                        dis[l][r] = dis[l][k] + dis[k][r];
                        num[l][r] = num[l][k] * num[k][r];
                    }else if(dis[l][r] == dis[l][k] + dis[k][r]) num[l][r] += num[l][k] * num[k][r];
                }
                printf(":%d %d %lld %d\n", l, r, dis[l][r], num[l][r]);
                if(num[l][r] == 2) ++ans;
            }
        }
        printf("%d\n", ans);
    }
return 0;
}
