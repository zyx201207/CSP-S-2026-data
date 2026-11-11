#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001],s[500001],n,m,ans;
int al,ar;
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			int tmp=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(tmp>m)
				l=mid+1;
			else
				r=mid;
		}
		if(i-l+1>ans)
			ans=i-l+1;
	}	
	cout<<ans<<'\n';
}
