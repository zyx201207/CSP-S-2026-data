#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],res=1,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			res=i;
		if(a[i]*res<=s[i]+m)
			ans=i;
		else
			break;
	}
	cout<<ans;
	return 0;
}