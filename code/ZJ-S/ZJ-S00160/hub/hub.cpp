#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int testcase,T,n,k,as,mxd[N],quanjux,quanjuy;
vector<int>g[N],res;
vector<vector<int> >dp;
void dfs(int x,int y)
{
	dp[x][0]=1;
	dp[x][1]=0;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v==y)
		{
			continue;
		}
		dfs(v,x);
		mxd[x]=max(mxd[x],mxd[v]+1);
		vector<int>tp(k+1,0x3f3f3f3f);
		for(int j=1;j<=k;j++)
		{
			if(dp[x][j]>=0x3f3f3f3f)
			{
				continue;
			}
			for(int l=0;j+l<=k;l++)
			{
				tp[j+l]=min(tp[j+l],max(dp[x][j],dp[v][l]));
			}
		}
		int neo=max(dp[x][0],dp[v][0]+1);
		dp[x].swap(tp);
		dp[x][0]=neo;
	}
	/*
	if(quanjux!=2||quanjuy!=3)
	{
		return;
	}
	for(int i=0;i<=k;i++)
	{
		cerr<<"dp "<<x<<" "<<i<<" "<<dp[x][i]<<"\n";
	}
	cerr<<"mxd["<<x<<"]="<<mxd[x]<<"\n";
	*/
}
void dfs2(int x,int y,int z)
{
	//if(quanjux==2&&quanjuy==3)
	//cerr<<"dfs2 "<<x<<" "<<y<<" "<<z<<"\n";
	for(int i=1;i<=k;i++)
	{
		res[i]=min(res[i],max(dp[x][i],z));
	}
	int mx=-0x3f3f3f3f,smx=-0x3f3f3f3f;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v==y)
		{
			continue;
		}
		int p=mxd[v]+1;
		if(p>mx)
		{
			smx=mx;
			mx=p;
		}
		else if(p>smx)
		{
			smx=p;
		}
	}
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v==y)
		{
			continue;
		}
		int nx=max(0,max(z,(mxd[v]+1==mx?smx:mx)))+1;
		dfs2(v,x,nx);
	}
}
vector<int>query(int x,int y)
{
	res=vector<int>(k+1,0x3f3f3f3f);
	dfs(x,y);
	dfs2(x,y,-0x3f3f3f3f);
	return res;
}
int calc(int x,int y)
{
	quanjux=x;
	quanjuy=y;
	dp=vector<vector<int> >(n+1,vector<int>(k+1,0x3f3f3f3f));
	for(int i=1;i<=n;i++)
	{
		mxd[i]=0;
	}
	vector<int>qle=query(x,y),qri=query(y,x);
	/*
	for(int i=1;i<=k;i++)
	{
		cerr<<"? "<<x<<" "<<y<<" "<<i<<" "<<qle[i]<<" "<<qri[i]<<"\n";
	}
	*/
	int as=0x3f3f3f3f;
	for(int i=1;i<k;i++)
	{
		as=min(as,max(qle[i],qri[k-i]));
	}
	return as;
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	as=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int v=g[i][j];
			if(i<v)
			{
				int tp=calc(i,v);
				//cerr<<"! "<<i<<" "<<v<<" "<<tp<<"\n";
				as=min(as,tp);
			}
		}
	}
	printf("%d\n",as);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&testcase,&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
