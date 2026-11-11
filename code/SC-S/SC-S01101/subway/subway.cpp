#include<bits/stdc++.h>
using namespace std;
int w[600000];
int li[550][550];
bool l2[550][550];
int k1[600000],k2[600000],x,y,ans=0;//每条线暂存
int c,n,m,d,q,num=100000000;
bool h=0;
void csh()
{
	for(int i=0;i<=549;i++)
	{
		for(int j=0;j<=549;j++)
		{
			l2[i][j]=0;
		}
	}
}
void dfs(int cs,int m1)
{
	
	if(cs==m1)
	{
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(l2[cs][i]==1||l2[i][cs]==1)
		{
			continue;
		}
		else
		{
			if(li[cs][i]==0)
			{
				continue;
			}
			else
			{
				l2[cs][i]=1;
				l2[i][cs]=1;
				ans=ans+li[cs][i];
				dfs(i,m1);
				l2[cs][i]=0;
				l2[i][cs]=0;
			}
		}
	}
	
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=549;i++)
	{
		for(int j=0;j<=549;j++)
		{
			li[i][j]=0;
		}
	}
	csh();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		memset(k1,0,sizeof(k1));
		memset(k2,0,sizeof(k2));
		for(int j=1;j<=k;j++)
		{
			
			cin>>k1[j]>>k2[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int p=1;p<=k;p++)
			{
				if(p==j)
				{
					p++;
				}
				li[k1[j]][k1[p]]=k2[p]+li[k1[j]][k1[p]];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		num=0;
		csh();
		ans=0;
		dfs(x,y);
		cout<<ans<<endl;
	}
	
}