#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ttt=0;
int a[500005];
int k[501];
bool dd[501];
struct node{
    int hao;
    long long time;
    node (int x,long long y){
        hao=x,time=y;
    } 
};
vector<node> lu[501];
long long dfs(int sx,int ex,long long ans){
    if(sx==ex){
        return ans;
    }
    long long anss=1e18;
    for(int i=1;i<=n;i++){
        if(dd[i])
            continue;
        for(int j=1;j<=k[i];j++){
            if(lu[i][j].hao==sx){
                dd[i]=true;
                for(int kk=1;kk<=k[i];kk++)
                    if(kk!=j)
                        anss=min(anss,dfs(lu[i][kk].hao,ex,lu[i][kk].time+lu[i][j].time));
                dd[i]=false;
            }
        }
    }
    return ans+anss;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        lu[i].push_back(node(0,0ll));
        for(int j=1;j<=k[i];j++){
            int x;
            long long y;
            scanf("%d%lld",&x,&y);
            lu[i].push_back(node(x,y));
        }
    }
    for(int i=1;i<=q;i++){
        int sx,ex;
        scanf("%d%d",&sx,&ex);
        memset(dd,0,sizeof(dd));
        printf("%lld\n",dfs(sx,ex,0ll)+a[sx]+a[ex]);
        continue;
    }
    return 0;
}