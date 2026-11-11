#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long dp[5200][5200];
bool vis[5200][5200];
bool previs[5200][5200];
long long maxx;
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long g=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g=max(g,a[i]);
	}
	if(g<=1)
	{
		cout<<g;
		return 0;
	}
	
	for(int i=1;i<=m;i++)
	{
		
		
		
		for(int j=1;j<=n;j++)
		{
			long long num=0;
			long long sum=0;
			for(int k=1;k<=n;k++)
			{
				if(previs[k][j]==0)
				{ 
					long long p;
					if(i==1)p=a[j];
					else p=dp[i-1][k]&a[j];
					if(p>sum)
					{
						sum=p;
						num=k;
				
					}
				
					
				}
			
			}
			
						
						dp[i][j]=sum;
						for(int q=0;q<5200;q++)
						{
							vis[j][q]=previs[num][q];
						}
						vis[j][j]=1;
					
		}
		for(int i1=0;i1<5200;i1++)
		{
			for(int j1=0;j1<5200;j1++)
			{
				previs[i1][j1]=vis[i1][j1];
				vis[i1][j1]=0;
	
			}
			}
			
		
	}
	
			
	for(int i=1;i<=n;i++)
	{

		maxx=max(dp[m][i],maxx);

	}
	cout<<maxx;
	return 0;
}
	
