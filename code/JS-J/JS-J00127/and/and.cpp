#include<bits/stdc++.h>
using namespace std;
int a[200010],ans = 0;
int n, m;
void dfs(int t, int p, int x)
{
    if(t == m)
        ans = max(ans,x);
    else
        for(int i=p+1; i<=n; i++)
            dfs(t+1, i, x&a[i]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        dfs(1,i,a[i]);
    printf("%d",ans);
    return 0;
}
