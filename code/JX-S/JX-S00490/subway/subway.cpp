#include<bits/stdc++.h>
using namespace std;
const int N=507;
struct node
{
  int data,s;
};
int m,n,c,d,q,w[N],minx,tim[N][N];
vector<node>k[N];
bool r[N];
void dfs(int a,int b,int t,int l)
{
  for(int i=0;i<(int)k[a].size();i++)
  {
    node v=k[a][i];
    if(v.data==b)
    {
      minx=min(minx,t+tim[l][b]);
      return;
    }
    if(r[v.data])continue;
    r[v.data]=1;
    if(v.s==l)dfs(v.data,b,t,l);
    else dfs(v.data,b,t+tim[v.s][v.data]+tim[l][a],v.s);
  }
}
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);	
  scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
  for(int i=1;i<=m;i++)scanf("%d",&w[i]);
  for(int i=1;i<=n;i++)
  {
     int e;
     scanf("%d",&e);
     int pre=0;
     for(int j=1;j<=e;j++)
     {
        int a,t;
        scanf("%d%d",&a,&t);
        tim[i][a]=t;
        if(pre)
        {
          k[a].push_back((node){pre,i});
          k[pre].push_back((node){a,i});
        }
        pre=a;
     }
  } 
  for(int i=1;i<=q;i++)
  {
     int x,y;
     scanf("%d%d",&x,&y);
     minx=0x3f3f3f3f;
     for(int i=1;i<=n;i++)
     {
		 if(tim[i][x])
		 {
             memset(r,0,sizeof(r));
			 dfs(x,y,tim[i][x],i);}
     }
     int t=w[x]+w[y]+minx;
     printf("%d\n",t);
  }
  return 0;
}
