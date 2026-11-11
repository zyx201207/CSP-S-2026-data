#include <bits/stdc++.h>
using namespace std;
int a[200005];
int maxans=-1e9;
bool vis[200005];
int n,m;
void dfs(int level,int ans){
    if (level==m+1){
        maxans=max(maxans,ans);
        return;
    }
    for (int i=1;i<=n;++i){
        if (vis[i]){
            continue;
        }
        if (level==1){
            ans=a[i];
        }
        vis[i]=true;
        int f=ans;
        f &= a[i];
        dfs(level+1,f);
        vis[i]=false;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    dfs(1,0);
    printf("%d\n",maxans);
    return 0;
}
