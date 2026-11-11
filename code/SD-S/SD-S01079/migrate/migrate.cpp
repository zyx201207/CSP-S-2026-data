#include<bits/stdc++.h>
using namespace std;
long long t,n,c,d;
long long x[2000009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,n);
		cin>>n>>d;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])flag=0;
		}
		if(flag)
		{
			long long ans=d/(x[2]-x[1]),cnt=0;
			for(long long i=1;i<ans;i++)
			{
				for(long long j=i+1;j<=ans;j++)if(j+i+1<=n)cnt+=n-(j+i+1)+1;
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
 } 
