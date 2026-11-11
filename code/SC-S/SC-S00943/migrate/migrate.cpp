#include <bits/stdc++.h>
using namespace std;
struct AKIOI_GO{int x;long long t;};
int c,T,n,l,r,x,t;
long long u,a[5001],ans,f[5001],d[5001];
bool vis[5001];
vector<int>v[5001];
void bfs(int s){
    queue<AKIOI_GO>q;
    memset(d,0x3f,sizeof d),memset(f,0,sizeof f),memset(vis,0,sizeof vis),d[s]=0,f[s]=1,q.push({s,0});
    while(q.size()){
        x=q.front().x,t=q.front().t,q.pop();
        for(auto y:v[x]){
            if(d[y]==4557430888798830399)d[y]=t+1,f[y]=f[x],q.push({y,d[y]}),vis[y]=vis[x];
            else if(d[y]==d[x]+1&&!vis[y]){
                // if(vis[x]){vis[y]=1;continue;}
                f[y]+=f[x];
                if(f[y]>2)vis[y]=1;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&u),ans=0;
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>u)break;
                v[i].emplace_back(j),v[j].emplace_back(i);
            }
        }
        for(int i=1;i<n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++)if(f[j]==2&&!vis[j])ans++;
            // for(int j=1;j<=n;j++)printf("%lld ",d[j]);
            // printf("\n");
            // for(int j=1;j<=n;j++)printf("%lld ",f[j]);
            // printf("\n");
            // for(int j=1;j<=n;j++)printf("%d ",vis[j]);
            // printf("\n\n");
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}