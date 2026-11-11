#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int a[500010],f[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int f=0;
	int ans=1;
	int l=1,r=1;
	while(r<n)
	{
		r++;
		f+=(a[r]-a[r-1])*(r-l);
		while(f>m)
		{
			f-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
 } 
