#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[500010],top,ans[500010],l[500010],k[500010],w[500010],p;
bool b[500010],d[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    if (n <= 10000) {
        for (int i = 1; i <= n; i++) {
            top = 0;
            for (int j = i; j <= n; j++)
                if (!b[a[j]])
                    c[++top] = a[j], b[a[j]] = 1;
                else {
                    while (c[top] != a[j])
                        b[c[top]] = 0, top--;
                }
            for (int j = 1; j <= m; j++)
                ans[j] += b[j], b[j] = 0;
        }
        for (int i = 1; i <= m; i++)
            printf("%d ",ans[i]);
    }
    else {
        for (int i = n; i >= 1; i--) {
            if (d[a[i]])
                b[i] = 1;
            else
                d[a[i]] = 1;
            if (w[a[i]] == 0)
                w[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            while (w[k[p]] < i && p > 0)
                p--;
            ans[a[i]] += i - l[p];
            if (b[i])
                k[++p] = a[i], l[p] = i;
        }
        for (int i = 1; i <= m; i++)
            printf("%d ",ans[i]);
    }
}
