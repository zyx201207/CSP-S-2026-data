//重在参与，重在爆零-----我和我的同学 
#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[5005][5005],g[5005][5005],h[5005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int sum;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		a[0]=-10000001;
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k>=1;k--)
				{
				//	cout<<j<<" "<<k<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
					if(a[j]-a[k]>=d)
					{
						if(a[j]-a[k]==d) h[j]=k;
						else h[j]=k-1;
						break;
					}
				}
			}
			/*for(int j=1;j<=n;j++)
			{
				cout<<h[j]<<" ";
			}*/
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k<=n;k++)
				{
					if(h[k]!=0)
					{
						//cout<<j<<" "<<k<<endl;
						g[j][k]=g[j][h[k]]+1;
					}
					else
						g[j][k]=1;
				}
			}
			/*for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					cout<<g[i][j]<<" ";
				}
				cout<<endl;
			}*/
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k<=n;k++)
				{
					int suuum=0,zhi=100000007;
					for(int l=j;l<=k-1;l++)
					{
						if(g[j][l]+g[l][k]<zhi)
						{
							zhi=g[i][k]+g[k][j];
							suuum=1;
						}
						else if(g[j][l]+g[l][k]==zhi)
						{
							suuum++;
						}
					}
					if(suuum==2) 
					{
						sum++;
					}
				}
			}
	}
	cout<<sum;
}