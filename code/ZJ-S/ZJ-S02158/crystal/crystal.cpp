#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500003],m,s,f[500004];
map<long long,int> ma;
bool check(int x)
{
//	cout<<x<<"\n";
	long long sum=1e18+1;
	for(int i=1;i<=n-x+1;i++)
	{
		long long s=a[i+x-1]*x-(f[i+x-1]-f[i-1]);
	//	cout<<i<<" "<<i+x-1<<" "<<s<<"\n";
		sum=min(sum,s);
	}
//	cout<<"\n";
	if(sum<=m)
		return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//cout<<"\n\n";
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
	}
	int l=0,r=n+1,mid,ans;
	while(l<r)
	{
		
		mid=(l+r)>>1;
	//	cout<<l<<" "<<r<<" "<<mid<<" ";
		if(check(mid))
		{
		//	cout<<"1 ";
			l=mid+1;
			ans=mid;
			s=mid;
		}
		else
		{
		//	cout<<"2 ";
			r=mid;
		}
//		cout<<"\n";
	}
	cout<<ans;
	return 0;
}