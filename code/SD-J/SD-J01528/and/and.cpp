#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
