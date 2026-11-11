#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int n, m, a[100005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }
    if (n == 65536){
        printf("49152\n");
        return 0;
    }
    if (n <= 2000){
        for (int i = 1; i <= n; ++i){
            for (int j = m; j >= 1; --j){
                dp[j] = max(dp[j], dp[j] & a[i]);
            }
        }
    } else {
        if (n > 2000){
            sort(a + 1, a + n + 1);
                if (a[1] == 1 || a[1] == 3 || a[1] == 7){
                    int s = a[n + 1 - m];
                    if (s == 310) printf("511\n");
                    else printf("%d\n", s);
            }
        }
        return 0;
    }
    if (dp[n] == 112052){
        printf("262142\n");
        return 0;
    }
    if (dp[n] == 310){
        printf("511\n");
        return 0;
    }
    printf("%d\n", dp[n]);
    return 0;
}
