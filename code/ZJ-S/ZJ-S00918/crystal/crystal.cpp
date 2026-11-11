#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,ans;
int a[N],b[N];
map<int,int>mp;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			int sum=(i-mid+1)*a[i]-(b[i]-b[mid-1]);
			if(sum<=m)r=mid;
			else l=mid+1;
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
1 2 3 4 5
*/
