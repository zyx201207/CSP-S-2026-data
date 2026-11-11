#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,d1,a[2000001],b[2000001],c[1000001],d[1000001];		
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c1,c2;
	cin>>c1>>c2;
	for(long long c3=1;c3<=c2;c3++)
	{
		long long t=0;
		cin>>n>>d1;
		for(long long i=1;i<=n;i++)
			cin>>a[i];
		for(long long i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]>d1)
			{
				n=i-1;
				break;				
			}
		}
		for(long long i=1;i<=n;i++)
		{
			if(a[n]-a[i]<=d1)
				break;
			long long m=0;
			b[2]=1;
			for(long long j=i+2;j<=n;j++)
			{
				if((a[j]-a[i])%d1==0)
					b[j]=(a[j]-a[i])/d1;
				else
					b[j]=(a[j]-a[i])/d1+1;					
				if(b[j]!=b[j-1])
				{
					m++; 
					c[m]=j-1; 
					//cout<<c[m]<<" ";
				}
			//	cout<<b[j]<<" ";		
			}
			for(long long j=2;j<=c[1];j++)
				d[j]=1;
			c[0]=2;
			c[m+1]=n;
			for(long long j=1;j<=m;j++)
			{
				for(long long x=c[j]+1;x<=c[j+1];x++)
				{
					for(long long p=c[j-1];p<=c[j];p++)
					{
						if(a[x]-a[p]<=d1)
							d[x]=d[x]+d[p];
						//cout<<d[x]<<" ";
					}
				}
			}
			for(long long j=1;j<=n;j++)
			{ 
				//cout<<d[i]<<" ";
				if(d[j]==2)
					t++;
				b[j]=0;
				c[j]=0;
				d[j]=0;
			}
		}
		cout<<t<<endl;
	}
return 0;	
} 
