#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[1010][2010];
int tin[2010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T,n,m,d,q,t,be,w;
	cin>>T>>n>>m>>d>>q;
	for(int i=0;i<=1010;i++)
	{
		for(int j=0;j<=1510;j++)
		{
			a[i][j]=2147483647;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>tin[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=0;j<t;j++)
		{
			cin>>be>>w;
			a[be][m+i]=w;
			a[m+i][be]=w;
		}
	}
	int begi,en;
	for(int k=1;k<=n+m;k++)
	{
		for(int i=1;i<=n+m;i++)
		{
			for(int j=1;j<=n+m;j++)
			{
					a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
			}
		}
	}
	while(q--)
	{
		cin>>begi>>en;
		cout<<a[begi][en]+tin[begi]+tin[en]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

