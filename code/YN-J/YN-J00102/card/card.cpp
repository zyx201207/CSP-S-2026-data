#include <bits/stdc++.h>
#define N 500005
#define M 300005
typedef long long ll;

int n, m, a[N];
int val[N], id[N], cnt;
int ans[M];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int j = i; j <= n; j++)
        {
            if (id[a[j]] <= cnt && val[id[a[j]]] == a[j])
            {
                cnt = id[a[j]];
            }
            else
            {
                val[++cnt] = a[j];
                id[a[j]] = cnt;
            }
        }
        for (int j = 1; j <= cnt; j++)
        {
            ans[val[j]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}