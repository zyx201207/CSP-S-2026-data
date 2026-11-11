#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int cnt=0;
int num[30];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		// cout<<1<<endl;
		cout<<a[n];
		return 0;
	}
	// cout<<m<<n<<endl;
	if(m==n)
	{
		// cout<<2<<endl;
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2 && n<=5000)
	{
		// cout<<1<<endl;
		int fmx=-1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int res=a[i]&a[j];
				fmx=max(fmx,res);
			}
		}
		cout<<fmx;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
	
}
