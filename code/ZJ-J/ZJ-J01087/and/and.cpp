#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n)
	{
		int ans;
		cin>>ans;
		for(int i=1; i<n; i++)
		{
			int n;
			ans&=n;
		}
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			int a;
			cin>>a;
			ans=max(ans,a);
		}
		cout<<ans;
		return 0;
	}
	else cout<<0;
	return 0;
}

