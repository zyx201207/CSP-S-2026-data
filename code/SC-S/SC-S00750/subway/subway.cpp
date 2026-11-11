#include<bits/stdc++.h>
using namespace std;
int w[1000005];
int a[1000005][505]; 
int b[1000005][505]; 
int k[1000005];
int kn[505][1000005]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p; 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}//地铁口走到站厅的时间
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int z;
			cin>>z;
			b[z][i]=1; 
			kn[i][j]=z;
			cin>>a[z][i];
		}//站厅到地铁站的时间 
	} 
	long long num=0;
	for(int i=1;i<=p;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		int b1[100005],b2[100005];
		num=num+w[a1]+w[a1];
		int max1=0;
		for(int j=1;j<=n;j++)
		{
			if(kn[j][a1]==1&&kn[j][a1]==1)
			{
				num+=a[a1][j]+a[a2][j];
				cout<<num;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int j1=1;j1<=n;j1++)
			{
				if(b[a1][j]==b[a2][j1]&&b[a2][j1]==1)
				{
					for(int j2=1;j2<=n;j2++)
					{
						for(int j3=1;j3<=n;j3++)
						{
							if(kn[j][j2]==kn[j1][j3]&&kn[j1][j3]==1)
							{
								if(a1<kn[j1][j3]&&kn[j1][j3]<a2)
								{
									max1=kn[j1][j3];
									num=num+a[kn[j1][j3]][j1]+a[kn[j1][j3]][j1];
									j=n+1;
								}
								else if(a1<kn[j1][j3]&&kn[j1][j3]<a2)
								{
									max1=kn[j1][j3];
									num=num+a[kn[j1][j3]][j1]+a[kn[j1][j3]][j1];
									cout<<num;
									j=n+1;
								}
								max1=kn[j1][j3];
							}
						}
					}
				}
			}
		}
	}
	return 0;
}