#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],s[N],ans,n,m;
bool check(int mid)
{
	for(int i=1;i+mid-1<=n;i++)
		if(a[i+mid-1]*mid-s[i+mid-1]+s[i-1]<=m)	return 1;
	return 0;
}
signed main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	cout<<ans;
	return 0;
}
