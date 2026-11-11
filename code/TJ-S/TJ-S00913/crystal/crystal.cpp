#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long cha=0;
		cha=(a[i]-a[i-1])*(i-1);
		if(cha>=m)
		{
			cout<<ans+1;
			return 0;
		}
		ans++;
	}
	return 0;
}
