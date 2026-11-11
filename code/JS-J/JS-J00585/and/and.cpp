#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],c[200010][35],s[200010],top,ans[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        int aa = a[i];
        for (int j = 30; j >= 1; j--)
            c[i][j] = a[i] % 2, a[i] /= 2;
        a[i] = aa;
        ans[i] = i;
    }
    for (int i = 1; i <= 30; i++) {
        top = 0;
        for (int j = 1; j <= n; j++)
            if (c[ans[j]][i])
                s[++top] = ans[j];
        if (top < m)
            continue;
        for (int j = 1; j <= top; j++)
            ans[j] = s[j];
        n = top;
    }
    int an = a[ans[1]];
    for (int i = 2; i <= m; i++)
        an = an & a[ans[i]];
    printf("%d",an);
}
