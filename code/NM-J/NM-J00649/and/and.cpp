#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 10;
int n,m;
ull a[N],mx = 0;
bool vis[N];
void dfs(int x,ull p){
    if (x == m){
        mx = max(mx,p);
    }
    for (int i = 0;i < n;++ i){
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(x + 1,(p & a[i]));
        vis[i] = 0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;++ i){
        scanf("%llu",&a[i]);
    }
    for (int i = 0;i < n;++ i){
        vis[i] = 1;
        dfs(1,a[i]);
        vis[i] = 0;
    }
    printf("%llu\n",mx);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
