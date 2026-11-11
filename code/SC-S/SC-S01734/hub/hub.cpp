#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,x[15],y[15],fa[15],d[15],dis[15][15],sz[1111],ans;
vector<int>v[15];
void dfs(int x,int f){
    fa[x]=f;
    d[x]=d[f]+1;
    for(int&i:v[x])
        if(i!=f)dfs(i,x);
}
inline int DIS(int x,int y){
    int res=0;
    while(d[x]>d[y])x=fa[x],res++;
    while(d[x]<d[y])y=fa[y],res++;
    while(x!=y)x=fa[x],res++,y=fa[y],res++;
    return res;
}
inline bool ch(int S){
    int bs=0;
    for(int i=1;i<n;i++)
        if((S&(1<<x[i]>>1))&&(S&(1<<y[i]>>1)))
            bs++;
    return bs>=sz[S]-2;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    for(int i=1;i<=1000;i++)
        sz[i]=sz[i&(i-1)]+1;
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d",x+i,y+i),
            v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        dfs(1,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=DIS(i,j);
        ans=100;
        for(int S=1;S<1<<n;S++)if(sz[S]==k&&ch(S)){
            int ma=0;
            for(int i=1;i<=n;i++){
                int mi=100;
                for(int j=1;j<=n;j++)
                    if(S&(1<<j>>1))
                        mi=min(mi,dis[i][j]);
                ma=max(ma,mi);
            }
            ans=min(ma,ans);
        }
        printf("%d\n",ans);
    }
}