#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[210000];

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort (a + 1, a + n + 1);
    if (m == 1){
        printf("%d", a[n]);
        return 0;
    }
    int ans = 0;
    if (m == 2){
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i] & a[j] >= ans)
                    ans = a[i] & a[j];
        printf("%d", ans);
        return 0;
    }
    ans = 1;
    if (m == n){
        for (int i = 1; i <= n; i++)
            ans &= a[i];
        printf("%d", ans);
        return 0;
    }
    if (m == n - 1){
        int sum = 0;
        ans = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
                if (j != i)
                    sum &= a[j];
        }
        if (sum > ans)
            ans = sum;
    }
    return 0;
}
