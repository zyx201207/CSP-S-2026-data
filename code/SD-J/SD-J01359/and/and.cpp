#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005],p[200005][25];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		p[i][0]=a[i];
	}
	for(int k=1;k<=20;k++)
	{
		for(int i=1;i+(1<<k)-1<=n;i++)
		{
			p[i][k]=p[i][k-1]&p[i+(1<<(k-1))][k-1];
		}
	}
	for(int i=1;i<=n-m+1;i++)
	{
		long long res=(1<<n)-1,k=i;
		for(int j=log2(m)+1;j>=0;j--)
		{
			if(k==i+m-1)
			{
				break;
			}
			if(k+(1<<j)<=i+m-1)
			{
				res&=p[k][j];
				k=i+(1<<j);
				
			}
			
		}
		
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
