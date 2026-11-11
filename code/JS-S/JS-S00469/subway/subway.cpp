#include<bits/stdc++.h>
#define N 500010
#define  ll long long
using namespace std;
int kk[51],a,t,c,n,m,d,q;
ll val[N],dis[510][510];
struct node{
    int v;ll w;
};
vector<node>e[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++) cin>>val[i];
    for(int i=1;i<=n;i++)
    {
       dis[i][i]=0;
       cin>>kk[i];
       for(int j=1;j<=kk[i];j++)
       {
         cin>>a>>t;
         e[a].push_back({i,t});
       }
    }
    for(int x=1;x<=m;x++)
    {
         for(auto i:e[x])
         {
            for(auto j:e[x])
            {
              if(i.v!=j.v) 
              {
				  dis[i.v][j.v]=min(dis[i.v][j.v],i.w+j.w);
				  dis[j.v][i.v]=min(dis[j.v][i.v],i.w+j.w);
			  }
            }
         }
    }
    for(int i=1;i<=n;i++)
     for(int k=1;k<=n;k++)
      for(int j=1;j<=n;j++)
       {
          dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
       }
    for(int k=1;k<=q;k++)
    {
       int x,y;ll ans=0x7f7f7f7f7f;cin>>x>>y;
       for(auto i:e[x])
        for(auto j:e[y])
        {
           ans=min(ans,i.w+j.w+dis[i.v][j.v]);
        }
       cout<<ans+val[x]+val[y]<<endl;
    }
    return 0;
}
