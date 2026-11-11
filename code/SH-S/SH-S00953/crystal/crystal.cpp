#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[n];
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int s=a[0],mx=0;
	for (int l=0,r=0;l<=r,r<n;)
	{
		if (a[r]*(r-l+2)-s<=m)
		{
			s+=a[++r];
			mx=max(mx,r-l+1);
		}
		else
			s-=a[l++];
	}
	cout<<mx;
	return 0;
}
