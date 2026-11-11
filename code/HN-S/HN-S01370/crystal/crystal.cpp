#include<bits/stdc++.h>
using namespace std;
long long m,n,ans,a[500005],c;
bool t=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)  c=a[i]-a[i-1];
		if(i>2&&c!=a[i]-a[i-1]) t=0;
	}
	if(t)
	{
		long long p=0;
		for(int i=1;i*c<=m;i++)
		{
			p+=i*c;
			if(p>m) break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		long long p=0,ans_=1;
		for(int j=i-1;j>=1;j--)
		{
			p+=a[i]-a[j];
			if(p>m) break;
			ans_++;
		}
		ans=max(ans,ans_);
		if(ans==n) break;
	}
	cout<<ans;
	return 0;
}
