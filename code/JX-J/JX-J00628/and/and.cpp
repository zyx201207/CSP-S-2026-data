#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,cnt,maxn=-1,s[200005];
bool vis[200005];
void dfs(int x,int b){
    if(x>m){
        int k=s[1];
        for(int i=2;i<=m;i++){
            k&=s[i];
        }
        if(k>maxn) maxn=k;
        return;
    }
    for(int i=b;i<=n;i++){
        if(!vis[i]){
            s[x]=a[i];
            vis[i]=1;
            dfs(x+1,i);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,1);
    printf("%d",maxn);
    return 0;
}
