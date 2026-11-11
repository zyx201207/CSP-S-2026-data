#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[500005];
int s[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	cout<<"0 ";
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<s[i]<<" ";
	}
//	cout<<"\n";
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int l=0,r=i-1;
		while(l<r)
		{
			int mm=(l+r)/2;
			if(s[i]-s[mm]-mm*(a[i]-a[mm])<=m)
			{
				r=mm;
			}
			else
			{
				l=mm+1;
			}
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}