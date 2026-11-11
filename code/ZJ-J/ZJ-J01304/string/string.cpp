#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		int x=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=x;
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans;
	return 0;
}