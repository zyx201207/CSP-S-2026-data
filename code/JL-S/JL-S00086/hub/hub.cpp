#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
vector<int>v[N];
int xx[N],yy[N],fa[N];
int lvl[N],sum[N],dist[N][N];
int n,k,ans;
bool flag[N];
void init(int x,int f)
{
	fa[x]=f;
	if(x!=1)lvl[x]=lvl[f]+1;
	for(auto i:v[x])
	{
		if(i==f)continue;
		init(i,x);
	}
}
void getans()
{
	for(int i=1;i<=n;i++)sum[i]=0;
	int res=k;
	for(int i=1;i<n;i++)
	{
		if(flag[xx[i]]&&flag[yy[i]])res--;
	}
	if(res>2)return;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		int minn=1e18;
		for(int j=1;j<=n;j++)
		{
			if(!flag[j])continue;
			minn=min(minn,dist[i][j]);
		}
		maxx=max(maxx,minn);
	}
	ans=min(ans,maxx);
}
void perm(int x)
{
	if(x==k+1)
	{
		getans();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		flag[i]=1;
		perm(x+1);
		flag[i]=0;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)dist[i][j]=0;
				else dist[i][j]=1e18;
			}
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			xx[i]=x,yy[i]=y;
		}
		init(1,1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					bool flag1=0,flag2=0;
					int tmp=i;
					if(k==i||k==1)flag1=1;
					if(k==j||k==1)flag2=1;
					while(tmp>1)
					{
						if(tmp==k)flag1=1;
						tmp=fa[tmp];
					}
					tmp=j;
					while(tmp>1)
					{
						if(tmp==k)flag2=1;
						tmp=fa[tmp];
					}
					if(!flag1||!flag2)continue;
					dist[i][j]=min(dist[i][j],lvl[i]+lvl[j]-2*lvl[k]);
				}
			}
		}
		perm(1);
		cout<<ans<<'\n';
	}
	return 0;
}
