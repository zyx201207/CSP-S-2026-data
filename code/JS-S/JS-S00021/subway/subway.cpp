#include <bits/stdc++.h>
using namespace std;
int main(){
    int c , n , m , d , q;
    scanf("%d%d%d%d%d" , &c , &n , &m , &d , &q);
    int a[2001][2001] , w[2001];
    memset(a , 0x3f , sizeof a);
    for (int i = 1 ; i <= m ; i++) cin >> w[i];
    int num[501][2];
    for (int i = 1 ; i <= n ; i++){
        int k;
        cin >> k;
        for (int j = 1 ; j <= k ; j++){
            cin >> num[j][0] >> num[j][1];
            for (int p = 1 ; p < k ; p++)
                a[num[p][0]][num[j][0]] = min(num[p][1] + num[j][1] , a[num[p][0]][num[j][0]]);
        }
    }
    long long dp[2001][2001];
    memset(dp , 0x3f , sizeof dp);
    for (int i = 1 ; i <= m ; i++)
        for (int j = 1 ; j <= m ; j++)
            for (int k = 1 ; k <= m ; k++)
                ;
    while (q--){
        int x , y;
        scanf("%d%d" , &x , &y);
        printf("%lld\n" , dp[x][y] + w[x] + w[y]);
    }
}
