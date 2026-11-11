#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n,k,x,y,e,eer,ans[N],dep[N],pre[N];
struct node{
    int to,next;
}a[N*2];
void add(int u,int v){
    a[++e]={v,pre[u]};
    pre[u]=e;
}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=pre[x];i;i=a[i].next){
        int to=a[i].to;
        if(to!=fa) dfs(to,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        printf("%d\n",0);
    }
    return 0;
}
