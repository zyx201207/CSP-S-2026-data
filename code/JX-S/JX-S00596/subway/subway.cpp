#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, M = 5e5 + 10, inf = 1e18;
int c, n, m, d, q;
int x, y;
int w[M], k[N];
vector<int> a[N], t[N];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i ++){
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &k[i]);
        for(int j = 1; j <= k[i]; j ++){
            int tmp1, tmp2;
            scanf("%lld%lld", &tmp1, &tmp2);
            a[i].push_back(tmp1);
            t[i].push_back(tmp2);
        }
    }
    while(q --){
        scanf("%lld%lld", &x, &y);
        int sum1 = 0, sum2 = 0;
        int pos = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= k[i]; j ++){
                if(a[i][j] == y){
                    sum1 = i, sum2 = j;
                    break;
                }
                if(a[i][j] == x){
                    pos = j;
                }
            }
        }
        printf("%lld\n", w[x] + t[sum1][pos] + t[sum1][sum2] + w[y]);
    }
    return 0;
}