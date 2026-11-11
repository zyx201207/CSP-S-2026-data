#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,h=0,w[50005],k[505],a[505][50005],t[505][50005],x[10005],y[10005];
struct man
{
	int l,r,m;
};
bool f(int x,int y)
{
	int x1=0,y1=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(x==a[i][j])
			{
				x1=-1;
				
			}
			if(y==a[i][j])
			{
				y1=-1;
			}
		}
		if(x1==-1&&y1==-1)
		{
			return 1;
		}
		else if(x1==-1||y1==-1)
		{
			return 0;
		}
		else
		{
			x1=0;
			y1=0;
		}
	}
	return 0;
}
int f1(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(x==a[i][j])
			{
				return i;	
			}
		}
	}
	return 0;
}

man f2(int x,int y)
{
	man r={-1,-1,-1};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(x==a[i][j])
			{
				r.l=i;	
			}
			if(y==a[i][j])
			{
				r.r=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int o=1;o<=k[i];o++)
			{
				for(int p=1;p<=k[j];p++)
				{
					if(a[i][o]==a[j][p])
					{
						r.m=a[i][o];
						return r;
					}
				}
			}
		}
	}
	return {0,0,0};
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
		cin>>x[i]>>y[i];
		if(f(x[i],y[i]))
		{
			cout<<w[x[i]]+t[f1(x[i],y[i])][x[i]]+t[f1(x[i],y[i])][y[i]]+w[y[i]];
		}
		else
		{
			man z=f2(x[i],y[i]);
			cout<<w[x[i]]+t[z.l][x[i]]+t[z.l][z.m]+t[z.m][z.m-1]+t[z.m][y[i]-1]+w[y[i]];		
		}
		cout<<endl;
	}
	return 0;
}
