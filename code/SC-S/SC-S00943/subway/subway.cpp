#include <bits/stdc++.h>
using namespace std;
struct AKIOI_GO{int x;long long w;};
struct AKCTS_GO{
    int x;long long w;
    bool operator <(const AKCTS_GO &q)const{return q.w<w;}
};
int c,n,m,dd,qu,a[1001],k,s,e,x,p,cnt;
long long w[1001],t[1001],b[1001][1001],d[1001],z;
bool vis[1001];
vector<AKIOI_GO>v[1001];
priority_queue<AKCTS_GO>q;
long long zdl(){
    memset(d,0x3f,sizeof d),memset(vis,0,sizeof vis),d[s]=0;
    while(q.size())q.pop();
    q.push({s,0});
    while(q.size()){
        while(!q.empty()&&vis[q.top().x])q.pop();
        x=q.top().x,z=q.top().w,q.pop(),vis[x]=1;
        if(vis[e])return d[e];
        for(auto l:v[x])if(d[l.x]>d[x]+l.w)d[l.x]=d[x]+l.w,q.push({l.x,d[l.x]});
    }
    return d[e];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&dd,&qu);
    memset(b,0x3f,sizeof b);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++)scanf("%d %lld",a+j,t+j);
        for(int j=1;j<=k;j++)for(int e=1;e<=k;e++)if(j!=e)b[a[j]][a[e]]=min(b[a[j]][a[e]],t[j]+t[e]);
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)if(b[i][j]!=4557430888798830399)v[i].push_back({j,b[i][j]});
    while(qu--)scanf("%d%d",&s,&e),printf("%lld\n",zdl()+w[s]+w[e]);
    return 0;
}