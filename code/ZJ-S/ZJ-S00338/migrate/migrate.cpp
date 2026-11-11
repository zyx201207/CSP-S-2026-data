#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,ans,a[2000010],b[2000010],s[2000010];
vector<int> v[2000010];
struct node
{
	int x,y,z;
};
queue<node> q;
void bfs(int x)
{
	q.push({x,0,1});
	while(!q.empty())
	{
		int u=q.front().x,value=q.front().y,z=q.front().z;
		q.pop(); 
		if(b[u]>=0&&value!=b[u])continue;
		b[u]=value;
		s[u]+=z;
		for(int i=0;i<v[u].size();i++)
		if(b[v[u][i]]<0)q.push({v[u][i],value+1,z});
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
    	scanf("%lld%lld",&n,&m);
    	ans=0;
    	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    	sort(a+1,a+n+1);
    	for(int i=1;i<=n;i++)v[i].clear();
    	for(int i=1;i<=n;i++)
    	  for(int j=i+1;j<=n;j++)
    	    if(a[j]-a[i]<=m)
    	    {
    	    	v[i].push_back(j);
    	    	v[j].push_back(i);
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) b[j]=-1,s[j]=0;
			bfs(i);
			for(int j=1;j<=n;j++) ans+=(s[j]==2);
		}
		printf("%lld\n",ans/2);
	}
	return 0;
 } 
 /*
 10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
