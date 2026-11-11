#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef pair<int,int> PI;
priority_queue<PI,vector<PI>,greater<PI> > q;
struct node{
    int to,next,id;
}a[N*2];
int c,n,m,d,e,k,pre[N],x,y,t;
int w[N],dis[N];
bool f[N];
void add(int u,int v,int id) {
    a[++k]={v,pre[u],id};
    pre[u]=k;
}
int bfs(int x,int y){
    memset(dis,0x3f,sizeof(dis));
    memset(f,0,sizeof(f));
    q.push({0,x});
    dis[x]=0;
    f[x]=true;
    int id;
    while(!q.empty()) {
        PI p=q.top();
        q.pop();
        int h=p.second,d=p.first;
        if(f[h]) continue;
        f[h]=true;
        for(int i=pre[h];i;i=a[i].next) {
            int to=a[i].to;
            if(h==x||id==a[i].id) {
                dis[to] = 0;
                q.push({0,to});
                if(to==y) return dis[to];
            } else {
                if(dis[to] > d + w[h] + t) {
                    dis[to] = d+w[h]+t;
                    q.push({dis[to],to});
                    if(to==y) return dis[to];
                }
            }
        }
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&e);
    for(int i=1;i<=m;i++) {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",t);
        while(t--) {
            scanf("%d",&x);
            if(y!=0) {
                add(y,x,t);
                add(x,y,t);
            }
            y=x;
        }
        scanf("%d",&t);
    }
    while(e--) {
        scanf("%d%d",&x,&y);
        printf("%d\n",bfs(x,y));
    }
    return 0;
}
