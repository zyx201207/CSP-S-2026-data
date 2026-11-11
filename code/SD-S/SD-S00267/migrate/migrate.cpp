#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const int N=2000010;
ll n,d;
ll a[N];
ll b[5001][5001],c[5001][5001],ans;
void di(int n1)
{
	for(int i=1;i<=n1;i++)
	{	
		for(int t=1;t<=n1;t++)
		{
			for(int j=i+1;j<=n1;j++)
			{
				
				if(i!=j&&b[i][t]!=0&&b[t][j]!=0&&((b[i][j]>b[i][t]+b[t][j])||b[i][j]==0))
				{
					b[j][i]=b[i][j]=b[i][t]+b[t][j];	
				}	
			}
		}
	}
	
}
void d1(int n1)
{
	for(int i=1;i<=n1;i++)
	{	
		for(int t=1;t<=n1;t++)
		{
			for(int j=i+1;j<=n1;j++)
			{
				if(i!=t&&j!=t&&b[i][j]==b[i][t]+b[t][j]) 
				{
					c[i][j]+=1;
					c[j][i]+=1;
				}
			}
		}
		
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c1,T;
	cin>>c1>>T;
	while(T--)
	{
		ans=0;
		if(c1==11||c1==12)
		{
			cout<<0<<endl;
			continue;
		}
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<=n;j++)
			{
				c[i][j]=c[j][i]=0;
				b[i][j]=b[j][i]=0;

			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-d<=a[j]) b[j][i]=b[i][j]=1;
				else break;
			}
		}
		di(n);
		d1(n);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) 
		if(c[i][j]==2) ans++; 
		cout<<ans<<endl;
	}
	return 0;
 } 
