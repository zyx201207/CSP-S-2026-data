#include<bits/stdc++.h>
using namespace std;
const int maxn=20005,maxm=80005;
int c,n,m,d,qe;int k[maxn],w[maxn];int head[maxn],nxt[maxm],ver[maxm],val[maxm],tot=1;int cnt;long long dis[maxn];bool vis[maxn];long long f[1005][1005];
struct edge{
    int x,y,z;
    friend bool operator <(edge a,edge b){
        return a.z>b.z;//小根堆
    }
};
priority_queue< edge >q;
void add(int x,int y,int z){
    nxt[++tot]=head[x];head[x]=tot;ver[tot]=y;val[tot]=z;
}
long long dijisatra(int st,int ter){
    memset(vis,0,sizeof vis);
    q=priority_queue<edge>();
    for(int i=1;i<=cnt;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
    dis[st]=0;
    for(int i=head[st];i;i=nxt[i]){
        q.push(edge{st,ver[i],val[i]});
    }
    while(q.size()){
        edge cur=q.top();q.pop();
        if(dis[cur.y]>dis[cur.x]+cur.z){
            dis[cur.y]=dis[cur.x]+cur.z;
            if(cur.y==ter)continue;
            if(!vis[cur.y]){
                for(int i=head[cur.y];i;i=nxt[i])q.push(edge{cur.y,ver[i],val[i]});
                vis[cur.y]=1;
            }
        }
    }
    return dis[ter];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&qe);
    if((c>=1 && c<=8) || (c>=12 && c<=15)){
        cnt=m;int a,t,x,y,last;
        for(int i=1;i<=m;i++)scanf("%d",&w[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);last=-1;
            for(int j=1;j<=k[i];j++){
                scanf("%d %d",&a,&t);
                add(++cnt,a,t);add(a,cnt,t);
                if(last!=-1){
                    add(last,cnt,0);add(cnt,last,0);
                }
                last=cnt;
            }
        }
        while(qe--){
            scanf("%d %d",&x,&y);
            printf("%lld\n",(long long)w[x]+(long long)w[y]+dijisatra(x,y));
        }
    }else if(c>=9 && c<=11){
        int a1,a2,t1,t2;
        for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)f[i][j]=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=m;i++)f[i][i]=0;
        for(int i=1;i<=m;i++)scanf("%d",&w[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);
            if(k[i]==2){
                scanf("%d%d%d%d",&a1,&t1,&a2,&t2);
                f[a1][a2]=min(f[a1][a2],(long long)(t1+t2));f[a2][a1]=min(f[a2][a1],(long long)(t1+t2));
            }else{
                for(int j=1;j<=k[i];j++)scanf("%d%d",&a1,&t1);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    if(f[i][j]>f[i][k]+f[k][j])f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
        while(qe--){
            int x,y;scanf("%d %d",&x,&y);
            printf("%lld\n",(long long)w[x]+(long long)w[y]+f[x][y]);
        }
    }
}