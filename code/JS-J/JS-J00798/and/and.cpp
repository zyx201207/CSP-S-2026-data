#include <bits/stdc++.h>

using namespace std;

int n, m, a[200001], ans, sum[200001], id[200001];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if(n == m){
        for(int i = 1; i <= n; i++)
            ans &= a[i];
        printf("%d\n", ans);
        return 0;
    }
    if(m == 1){
        for(int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
        printf("%d\n", ans);
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        printf("%d\n", ans);
        return 0;
    }
    for(int i = 1; i <= 200001; i++)
        sum[i] = 1e9;
    int s = 1;
    for(int i = 1; i <= n; i++){
        int x = s - a[i];
        for(int j = 1; j <= m; j++)
            if(x < sum[j]){
                sum[j] = x;
                id[j] = i;
            }
        s *= 2;
    }
    for(int i = 1; i <= m; i++)
        ans = ans & a[id[i]];


}
