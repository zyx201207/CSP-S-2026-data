
#include <Bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000005],cnt1=1,ans,flag;

long long fdmin(long long a,long long b)
{
	if(a==b)
		return 0;
	flag++;
	long long cnt=2000005;
	for(int i=a+1;i<=b;i++)
	{
		if(x[i]-x[a]<=d)
		{
			int e=fdmin(i,b);
			if(cnt==e+1)
			{
				if(flag==1)
					cnt1++;
			}
			else if(cnt>e+1)
			{
				if(flag==1)
					cnt1=1;
				cnt=e+1;
			}
		}
	}
	flag--;
	return cnt;
} 

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
					continue;
				cnt1=1;
				fdmin(i,j);
				if(cnt1==2)
				{
					ans++;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
}
