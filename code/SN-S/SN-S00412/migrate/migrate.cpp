//SN-S00412 YangRuibin TYZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5,inf=1e9;
int type,T,n,gr[N],dep[N],f[N];
ll d,a[N],ans,dp[N][3][3];
void bfs(int st)
{
	queue<int>q;
	memset(dep,0,sizeof(int)*(n+1));
	memset(f,0,sizeof(int)*(n+1));
	q.push(st),dep[st]=1,f[st]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(f[x]==2)++ans;
		for(int to=x+1;to<=gr[x];to++)
		{
			if(dep[to]==dep[x])continue;
			f[to]=min(inf,f[to]+f[x]);
			if(dep[to]==dep[x]+1)continue;
			dep[to]=dep[x]+1,q.push(to);
		}
	}
}
void solve2()
{
	for(int st=n;st;st--)
	{
		f[st]=1,f[st-1]=0;
		int r=st;
//		cerr<<st<<"ST\n";
		while(r<=n)
		{
			if(f[r]==1&&f[r-1]==0)
			{
				if(gr[r]==r)break;
				r=gr[r];
				f[r]=f[r-1]=1;
				if(r>=2)f[r-2]=2;
				continue;
			}
			if(f[r]==1&&f[r-1]==2)
			{
				int p=gr[r-1];
				int j=gr[r];
				if(j==r)break;
				if(p==j)break;
				if(j>p)f[j]=1,f[j-1]=2;
				if(j-1>p)f[j-1]=1,f[j-2]=2;
				r=j;
				continue;
			}
			if(f[r]==1&&f[r-1]==1)
			{
				int p=gr[r-2];
				int i=gr[r-1];
				int j=gr[r];
				ans+=max(0,i-max(r,p));
//				cerr<<r<<' '<<p<<' '<<i<<":"<<max(0,i-max(r,p))<<"\n";
				if(j==r)break;
				if(p==j)break;
				if(j>i)f[j]=1,f[j-1]=2;//,cerr<<j-1<<"JJJ\n";
				if(j-1>i)f[j-1]=1,f[j-2]=2;
				if(i>p)f[i]=2,f[i-1]=2;
				r=j;
				continue;
			}
			if(f[r]==2)
			{
				int p=gr[r-1];
				int i=gr[r];
				ans+=max(0,i-max(r,p));
//				cerr<<"  "<<r<<' '<<p<<' '<<i<<":"<<max(0,i-max(r,p))<<"\n";
				if(i==r)break;
				if(p==i)break;
				f[i]=2,f[i-1]=2;
				r=i;
				continue;
			}
		}
	}
	printf("%lld\n",ans);
}
int cnt=0;
ll dfs(int r)
{
	int nr=f[r],nr1=f[r-1];
	++cnt;
	assert(cnt<=5e8);
	if(dp[r][nr][nr1]!=-1)
	{
		return dp[r][nr][nr1];
	}
	ll ret=0;
	if(f[r]==1&&f[r-1]==0)
	{
		if(gr[r]==r)return dp[r][nr][nr1]=0;
		r=gr[r];
		f[r]=f[r-1]=1;
		if(r>=2)f[r-2]=2;
		ret+=dfs(r);
		return dp[r][nr][nr1]=ret;
	}
	if(f[r]==1&&f[r-1]==2)
	{
		int p=gr[r-1];
		int j=gr[r];
		if(j==r)return dp[r][nr][nr1]=0;
		if(p==j)return dp[r][nr][nr1]=0;
		if(j>p)f[j]=1,f[j-1]=2;
		if(j-1>p)f[j-1]=1,f[j-2]=2;
		ret+=dfs(j);
		return dp[r][nr][nr1]=ret;
	}
	if(f[r]==1&&f[r-1]==1)
	{
		int p=gr[r-2];
		int i=gr[r-1];
		int j=gr[r];
		ret+=max(0,i-max(r,p));
//				cerr<<r<<' '<<p<<' '<<i<<":"<<max(0,i-max(r,p))<<"\n";
		if(j==r)return dp[r][nr][nr1]=0;
		if(p==j)return dp[r][nr][nr1]=0;
		if(j>i)f[j]=1,f[j-1]=2;//,cerr<<j-1<<"JJJ\n";
		if(j-1>i)f[j-1]=1,f[j-2]=2;
		if(i>p)f[i]=2,f[i-1]=2;
		ret+=dfs(j);
		return dp[r][nr][nr1]=ret;
	}
	if(f[r]==2)
	{
		int p=gr[r-1];
		int i=gr[r];
		ret+=max(0,i-max(r,p));
//				cerr<<"  "<<r<<' '<<p<<' '<<i<<":"<<max(0,i-max(r,p))<<"\n";
		if(i==r)return dp[r][nr][nr1]=0;
		if(p==i)return dp[r][nr][nr1]=0;
		f[i]=2,f[i-1]=2;
		ret+=dfs(i);
		return dp[r][nr][nr1]=ret;
	}
	return 0;
}
void solve_sol()
{
	for(int i=0;i<=n;i++)
		memset(dp[i],-1,sizeof(dp[i]));
	for(int st=n;st;st--)
	{
		f[st]=1,f[st-1]=0;
		int r=st;
		ans+=dfs(r);
	}
	printf("%lld\n",ans);
}
void solve()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	gr[n]=n;
	for(int i=n-1;i;i--)
	{
		gr[i]=gr[i+1];
		while(a[gr[i]]-a[i]>d)--gr[i];
	}
	if(type<=6)
	{
		for(int i=1;i<=n;i++)bfs(i);
		printf("%lld\n",ans);
		return;
	}
//	for(int i=1;i<=n;i++)cerr<<gr[i]<<' ';
//	cerr<<"GR\n";
	if(type<=10||(type>=15&&type<=18))
		return solve2(),void();
	return solve_sol(),void();
}
void clear()
{
	ans=0;cnt=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&type,&T);
	while(T--)solve(),clear();
	return 0;
}

