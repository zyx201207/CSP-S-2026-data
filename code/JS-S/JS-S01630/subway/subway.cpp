#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
typedef int IosType;
const int Plt(100000);
const int MAXM(500005);
IosType read(){
    IosType x=0,f=1; char ch;
    while((ch=getchar())<'0'||ch>'9')if(ch=='-')f=-1;
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
void write(IosType x){
    if(x<0)putchar('-'),x=-x;
    else if(x==0){putchar('0');return;}
    int buf[10005],cnt(0);
    while(x)buf[++cnt]=x%10,x/=10;
    while(cnt)putchar(buf[cnt--]+'0');
}

int c,n,m,d,Q,cnt,cnte;
int w[MAXM],head[MAXM],k[MAXM],dis[MAXM*10];
bool Doit[MAXM],vis[MAXM];
vector<pair<int,int> >plt[MAXM],route[MAXM];
struct Edge{
    int to,nxt,w;
}edge[MAXM*10];
void add(int u,int v,int w){
    edge[cnte].to=v;
    edge[cnte].w=w;
    edge[cnte].nxt=head[u];
    head[u]=cnte++;
}
void init(){
    memset(head,-1,sizeof head);
}
struct Node{
    int u,v,id,x;
}qt[MAXM],ans[MAXM];
bool cmpu(Node x,Node y){
    return x.u<y.u;
}
bool cmpid(Node x,Node y){
    return x.id<y.id;
}
struct Point{
    int u,d;
    bool operator>(const Point &lhs)const{
        return lhs.d>d;
    }
};
priority_queue<Point,vector<Point>,greater<Point> >q;
void dij(int s){
//    cout<<s<<endl;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f3f3f3f,sizeof dis);
    dis[s]=0;
    int u=s,d=0;
    //q.push({s,0});
    for(int i=2;i<=cnt+m*2;i++){
        d=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=cnt;j++)
            if(d>dis[j]&&!vis[j])d=dis[j],u=j;
        for(int j=1+Plt;j<=Plt+m;j++)
            if(d>dis[j]&&!vis[j])d=dis[j],u=j;
        for(int j=1+Plt*2;j<=Plt*2+m;j++)
            if(d>dis[j]&&!vis[j])d=dis[j],u=j;
        if(vis[u])break;
        vis[u]=1;
        //Point T=q.top();q.pop();
        for(int j=head[u];j>=0;j=edge[j].nxt){
            int v=edge[j].to,w=edge[j].w;
            if(dis[v]>d+w){
                dis[v]=d+w;
                //q.push({v,dis[v]});
            }
 //           printf("%d %d %d %d %d %d %d\n",v,w,u,j,dis[v],s,vis[u]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    init();
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1,tmp1,tmp2;j<=k[i];j++){
            tmp1=read(),tmp2=read();
            plt[tmp1].push_back({++cnt,tmp2});
            if(j>1) add(cnt-1,cnt,0);
        }
    }
    for(int i=1;i<=m;i++){
        add(Plt+i,Plt*2+i,w[i]);
        add(Plt*2+i,Plt+i,w[i]);
        for(int j=0;j<plt[i].size();j++){
            add(Plt+i,plt[i][j].first,plt[i][j].second);
            add(plt[i][j].first,Plt+i,plt[i][j].second);
        }
    }
    for(int i=1;i<=Q;i++)
        qt[i].u=read(),qt[i].v=read(),qt[i].id=i,Doit[qt[i].u]=1;
    sort(qt+1,qt+1+Q,cmpu);
    for(int i=1,j=1;i<=m;i++){
        if(Doit[i]){
            dij(Plt*2+i);
            for(;j<=Q&&qt[j].u==i;j++) ans[qt[j].id]={0,0,qt[j].id,dis[Plt*2+qt[j].v]};
        }
    }
    sort(ans+1,ans+1+Q,cmpid);
    for(int i=1;i<=Q;i++){
        write(ans[i].x);putchar('\n');
    }
    return 0;
}
