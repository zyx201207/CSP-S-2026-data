#include <bits/stdc++.h>
using namespace std;
const int inf=2147483647;
const int N=1e6+1;
struct edge{
 int to,len,next;
};
int n,m,s,tot=0;
int dis[N],head[N];
bool vis[N];
void add(int a int b,int c)
{
tot++;
e[tot].to=b;
e[tot].len=c;
e[tot].next=head[a];
head[a]=tot;
}
queue<int> que;
void spfa()
{
   for(int i=1;i<=n;i++)
   {
    dis[i]=inf;
    vis[i]=0;
   }
   dis[s]=0;
   que.push(s);
   vis[s]=1;
   while(!que.empty())
   {
    int u=que.front();
    que.pop();
    vis[u]=0;
    for(int i=head[u];i;i=e[i].next)
    {
    int to=e[i].to,w=e[i].len;
    if(dis[to]>dis[u]+w)
    dis[to]=dis[u]+w;
    if(vis[to]==0)
     {
      vis[to]=1;
      que.push(to);
     }
    }
   }
}
int c[N];
int d,q,qqqqqqqqq;
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
   cin>>qqqqqqqqq>>n>>m>>d>>q;
   for(int i=1;i<=m;i++)
   {
       cin>>c[i];
   }
   for(int i=1;i<)
}
