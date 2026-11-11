#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=1e7;
	for (int i=1;i<=n;i++)
	{
		ans=min(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
