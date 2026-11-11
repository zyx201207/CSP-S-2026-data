#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c1,t;
	cin >> c1 >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		int f=0,c=0;
		int minn=1e18;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(c<=2) c=a[i]-a[i-1];
			else
			{
				if(c!=a[i]-a[i-1]) f=1;
			}
			if(i!=1) minn=min(minn,a[i]-a[i-1]);
		}
		if(d<minn)
		{
			cout << 0<<endl;
			continue;
		 } 
		if(a[n]-a[1]<=d||c>=d)
		{
			cout << 0 <<endl;
			continue;
		 } 
		if(f==0)
		{
			int cnt=2*(d/c)+1;
			cnt=n-cnt+1;
			cout<<cnt+1<<endl;
		}
	}
	return 0;
}
