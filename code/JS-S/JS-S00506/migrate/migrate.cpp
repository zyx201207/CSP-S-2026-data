#include<bits/stdc++.h>
#define ll long long
using namespace std;
int op,_;
int n,m;
int a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>_;
	while(_--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		m=m/(a[2]-a[1]);
		if(m<=1)
		{
			cout<<0<<'\n';
		}
		else
		{
			int ans=0;
			ans=max(n-2*m+1,ans);
			cout<<ans<<'\n';
		}
	}
	return 0;
}