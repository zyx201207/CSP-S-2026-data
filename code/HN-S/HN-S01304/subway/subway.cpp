#include<bits/stdc++.h>
using namespace std;

int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=k*10+(c-'0');c=getchar();}
	return k*f;
}

int c,n,m,d,q;
int w[20005],l[20005][505],h[20005][505],time1[15005][15005],time2[15005][15005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			time1[i][j]=time2[i][j]=99999;
		}
	int k;
	for(int i=1;i<=n;i++)
	{
		k=read();
		int a,t;
		for(int j=1;j<=k;j++)
		{
			a=read();t=read();
			l[a][i]=t;
			h[i][++h[i][0]]=a;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=h[k][0];i++)
		{
			for(int j=1;j<=h[k][0];j++)
			{
				int x=h[k][i],y=h[k][j];
				if(x!=y)time1[x][y]=min(time1[x][y],l[x][k]+l[y][k]);
				time2[x][y]=min(time2[x][y],time1[x][y]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=m;j++)
			{
				if(time1[i][k]!=99999&&time1[k][j]!=99999)time2[i][j]=min(time2[i][j],time1[i][k]+time1[k][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		x=read();y=read();
		cout<<w[x]+w[y]+time2[x][y]<<"\n";
	}
	return 0;
}
