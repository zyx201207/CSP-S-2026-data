#include<bits/stdc++.h>
using namespace std;
const int M=500010;
int c,n,m,d,q;
int w[M];
int a[M],t[M];
int k[510];
struct station{
    int len=0;
    int wy[21]={0};
    int tim[21]={0};
}sta[M];
int numk[510];
int ans=INT_MAX;
bool flag[510];
inline void dfs(int x,int y,int num,int tm){
    for(int i=1;i<=sta[y].len;i++){
        if(sta[y].wy[i]==num){
            ans=min(ans,tm+w[y]+sta[y].tim[num]);
            return;
        }
    }
    for(int i=1;i<=sta[x].len;i++){
        int qwq=sta[x].wy[i];
        if(flag[qwq]){
            flag[qwq]=false;
            for(int j=numk[qwq-1]+1;j<=numk[qwq];j++){
                for(int ty=1;ty<=sta[a[j]].len;ty++){
                    if(flag[sta[a[j]].wy[ty]]){
                        dfs(a[j],y,sta[a[j]].wy[ty],tm+sta[x].tim[i]+sta[a[j]].tim[ty]);
                    }
                }
            }
            flag[qwq]=true;
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        numk[i]=numk[i-1]+k[i];
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[j],&t[j]);
            sta[a[j]].len++;
            sta[a[j]].wy[sta[a[j]].len]=i;
            sta[a[j]].tim[sta[a[j]].len]=t[j];
        }
    }
    for(int i=1;i<=q;i++){
        memset(flag,true,sizeof(flag));
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=1;j<=sta[x].len;j++){
            dfs(x,y,sta[x].wy[j],w[x]+sta[x].tim[j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
