#include<bits/stdc++.h>
using namespace std;
long long s[5005][5005],w[50001],a[550][51000],t[550][50100];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(s,0x3f3f3f3f,sizeof(s));
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(d==1)
	{
		while(q--)
		{
			int xx,yy;
			cin>>xx>>yy;
			if(xx>yy)swap(xx,yy);
			cout<<w[xx]+w[yy]<<endl;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(long long j=1;j<=k;j++)
		{
			for(long long l=1;l<=k&&l!=j;l++)
			{
			
				s[a[i][j]][a[i][l]]=min(s[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
				s[a[i][l]][a[i][j]]=min(s[a[i][l]][a[i][j]],t[i][j]+t[i][l]);
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			for(long long k=i+1;k<j;k++)
			{
				if(s[i][k]<100000000&&s[k][j]<100000000)
				{
					s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
				} 
			} 
		}
	}
	while(q--)
	{
		int xx,yy;
		cin>>xx>>yy;
		if(xx>yy)swap(xx,yy);
		cout<<s[xx][yy]+w[xx]+w[yy]<<endl;
	}
	return 0;
}
