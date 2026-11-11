#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,ans,a[200005];
char ch[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		cin>>ch[i];
	}
	l=1;
	r=n;
	while(true)
	{
		if(l>=r) break;
		int d=min(a[l],a[r]);
		if(ch[l]!=ch[r])
		{
			ans+=d;	
		}
		a[l]-=d;
		a[r]-=d;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
