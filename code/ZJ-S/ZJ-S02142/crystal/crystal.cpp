#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500004],b[500004],m,n;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=1;
	int r=n;
	int ans=1;
	cin>>a[1];
	for(int i=2;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
	{
		b[i]=a[i+1]-a[i];
	}
	int cnt=0;
	int s=1;
	for(int i=1;i<=n-1;++i)
	{
		ans=max(ans,s);
		if(b[i]==0)
		{
			s++;
		}
		else if(cnt+b[i]*s>m)
		{
			ans=max(s,ans);
			cnt=0;
			s=1;
		}
		else{
			cnt+=b[i]*s;
			s++;
			ans=max(ans,s);
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}