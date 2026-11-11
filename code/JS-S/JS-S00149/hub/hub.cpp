#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef long long ll;
int c,T;
int n,k,u,v,ans,dis[N][N];
bool vis[N];
pair<int,int> e[N];
void calc(){
    int comp=k;
    for(int i=1;i<n;i++){
        if(vis[e[i].first] && vis[e[i].second])comp--;
    }
    if(comp>2)return;
    int res=0;
    for(int i=1;i<=n;i++){
        int cnt=0x3f3f3f3f;
        for(int j=1;j<=n;j++){
            if(!vis[j])continue;
            cnt=min(cnt,dis[i][j]);
        }
        res=max(res,cnt);
    }
    ans=min(ans,res);
}
void f(int x,int cur){
    if(cur==k){
        calc();
        return;
    }
    if(cur+(n-x+1)<k)return;
    vis[x]=1;
    f(x+1,cur+1);
    vis[x]=0;
    f(x+1,cur);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k);ans=0x3f3f3f3f;
        memset(dis,0x3f3f3f3f,sizeof(dis));
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            dis[u][v]=dis[v][u]=1;
            e[i]=make_pair(u,v);
        }
        for(int x=1;x<=n;x++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][x]+dis[x][j]);
                }
            }
        }
        f(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
