#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a,m;
	cin>>n>>a;
	long long ans=1;
	if(n==a)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			ans=ans&m;
		}
	}else if(a==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			ans=max(ans,m);
		}
	}
	cout<<ans;
	return 0;
}
