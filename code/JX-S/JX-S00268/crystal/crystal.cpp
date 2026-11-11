#include<bits/stdc++.h>
using namespace std;
long long n,m,r,m1,ans,p,max1,min1;
bool pd=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	long long a[n+5],v[n+5];
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		max1=max(max1,a[i]);
		min1=min(min1,a[i]);
	} 
	sort(a+1,a+n+1);
	long long b[n+5][max1+2];
	for(long long i=0,j=min1;i<=max1-min1+1;i++,j++)
	{
		b[i][0]=j;
	}
	for(long long i=1;i<=max1-min1;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(b[i][0]-a[j]>=0) b[i][j]=b[i][0]-a[j];
			else 
			{
				b[i][j]=-1;
				pd=1;
			}
		}
		m1=m;
		if(pd)
		{
			for(long long j=1;j<=n;j++)
			{	
				if(b[i][j]==-1)
				{
					r=j-1;		
					break;
				}
			}
		}
		else r=n;
		ans=0;
		while(m1>0)
		{
			if(m1-b[i][r]>=0&&r>=1)
			{
				m1-=b[i][r];
				ans++;
				r--;		
			} 
			else break;
		}
		v[i]=ans;
		p=max(p,v[i]);
		pd=0;
		ans=0;
	}		 
	cout<<p;
	return 0;
}
