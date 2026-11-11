#include<bits/stdc++.h>
using namespace std;
int n,ans=1,t;
long long m,a[500005],s[500005];
bool f=0,p=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=a[2]-a[1];
	for(int i=2;i<=n;++i)
	{
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		if(s[i]<=m) ans=i;
		if(a[i]-a[i-1]!=t) f=1;
	}
	if(f==0)
	{
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n-ans;++i)
	{
		p=0;
		int j=i+ans;
		while(s[j]-s[i]<=m)
		{
			if(j+1<=n) j++;
			else p=1;
		}
		ans=j-i;
		if(p==1) ans++;
	}
	cout<<ans;
	return 0;
}
