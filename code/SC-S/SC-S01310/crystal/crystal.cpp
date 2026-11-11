#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],ps[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,mx=0;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
		int l=0,r=i-1,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*mid-(ps[i-1]-ps[i-mid-1])<=m)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		mx=max(mx,ans+1);
	}
	cout<<mx<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
//-std=c++14-static