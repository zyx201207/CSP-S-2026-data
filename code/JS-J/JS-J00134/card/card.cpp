#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n , m , a[MAXN] , num[MAXN];
int main() {
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        int pai[MAXN] = {0};
        bool vis[MAXN] = {0};
        memset(pai , 0 , sizeof(pai));
        memset(vis , 0 , sizeof(vis));
        for (int j = i ; j <= n ; j++) {
            int xiabiao = 0;
            if (vis[a[j]]) {
                for (int k = 1 ; ; k++) {
                    if (pai[k] == 0) {
                        pai[k] = a[j];
                        xiabiao = k;
                        vis[a[j]] = 1;
                        break;
                    }
                }
                for (int k = xiabiao - 1 ; k > 0 ; k--) {
                    if (pai[k] == pai[xiabiao] && k != xiabiao) {
                        pai[xiabiao] = 0;
                        break;
                    }
                    pai[k] = 0;
                    vis[k] = 0;
                }
                vis[a[j]] = 1;
            } else {
                for (int k = 1 ; ; k++) {
                    if (pai[k] == 0) {
                        pai[k] = a[j];
                        vis[a[j]] = 1;
                        break;
                    }
                }
            }
        }
        for (int j = 1 ; ; j++) {
            if (pai[j] == 0) break;
            num[pai[j]]++;
        }
    }
    for (int i = 1 ; i <= m ; i++) {
        printf("%d " , num[i]);
    }
    return 0;
}
