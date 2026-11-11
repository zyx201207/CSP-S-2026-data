#include<bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7;
int c,m,n,d,q,w[M],k[N],xr,yr,ans=0x3f3f3f3f;
int t[N][N],a[N][N];
bool f[N][N];
void dfs(int x,int l,int num,int step)
{
	if(f[l][num])
	{
		if(x==yr)
		{
			step+=t[l][num];
			ans=min(ans,step);
			return;
		}
		return;
	}
	f[l][num]=1;
	if(x==yr)
	{
		step+=t[l][num];
		ans=min(ans,step);
		return;
	}
	for(int j=1;j<=k[l];j++)
	{
		dfs(a[l][j],l,j,step);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x)
			{
				dfs(x,i,j,step+t[l][num]+t[i][j]);
			}
			break;
		}
	}
	f[l][num]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>xr>>yr;
		ans=0x3f3f3f3f;
		for(int ii=1;ii<=n;ii++)
		{
			for(int j=1;j<=k[ii];j++)
			{
				if(a[ii][j]==xr)
				{
					dfs(xr,ii,j,w[xr]+w[yr]+t[ii][j]);
				}
			}
		}
		memset(f,0,sizeof(f));
		cout<<ans<<endl;
	}
	return 0;
}