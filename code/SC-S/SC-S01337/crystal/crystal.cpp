#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

const int N = 5e5+15;
int n,m,arr[N];
int pre[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifndef DEBUG
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#else
	freopen("crystal4.in","r",stdin);
	freopen("myans.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>arr[i];
	}	
	sort(arr+1,arr+1+n);
	int res = 1;
	for(int i = 1;i<=n;i++)
	{
		pre[i] = pre[i-1]+arr[i];
		int l = 1,r = i,mid,ans = i;
		while(l <= r)
		{
			mid = (l+r)>>1;
			if((i-mid+1)*arr[i]-(pre[i]-pre[mid-1]) <= m)
			{
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		res = max(res,i-ans+1);
	}
	cout<<res<<'\n';
	
	return 0;
}
/*
14:48 FINISH 100
*/