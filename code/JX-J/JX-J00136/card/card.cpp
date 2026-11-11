#include<bits/stdc++.h>
using namespace std;

int a[500001], f = 1, r = 0;
int c[500001], b[100001];
       int d[100001];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) {
        f = 1; r = 0;
        for (int j = 1; j <= n - x; j++) {
            printf("%d ", c[j + x]);
            a[++r] = c[j + x];
            d[c[j + x]]++;
            if (d[c[j + x]] == 2) {
                for (int k = 1; k <= n - x; k++)
                    if (a[k] == a[r])
                        r = k;
            }
        }
        printf("\n");
        r = 0;
    }
    for (int i = 1; i <= m; i++)
            printf("%d ", b[m]);
    return 0;
}
