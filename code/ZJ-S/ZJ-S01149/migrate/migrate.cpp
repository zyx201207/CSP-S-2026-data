#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e2+100;
vector<int> v1[N],v2[N];
int C,T;
int n,vis[N];
ll m,a[N],f[N],cnt[N],minn,mink,ans;
void dfs(int x,int opt,int cnt)
{	
	if(x>opt) return ;
	if(x==opt)
	{
		if(cnt<minn&&cnt!=0)
		{
			minn=cnt;
			mink=1;
		}
		else if(cnt==minn) ++mink;
	}
	for(int i=0;i<v1[x].size();++i)
	{
		if(f[i]) continue;
		dfs(v1[x][i],opt,cnt+1);
		f[i]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;++i)
		  scanf("%lld",&a[i]);
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(int i=1;i<=n;++i)
		  for(int j=i+1;j<=n;++j)
		  	if(a[j]-a[i]<=m)
		  	{
		  	  v1[i].push_back(j);
		  	  v2[i].push_back(1);
			}
		for(int i=1;i<=n;++i)
		  for(int j=i+1;j<=n;++j)
		  {
		  	memset(f,0,sizeof f);
		  	minn=1e18;
			mink=0;
		  	dfs(i,j,0);
		  	if(mink==2) ++ans;
		  }
		printf("%lld\n",ans);
	}
	return 0;
}
