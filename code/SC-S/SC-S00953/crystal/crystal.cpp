#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,l=1,cnt=0,num=1;
int ans=1;
int a[500005];
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
	for(int i=2;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*num;
		while(cnt>m)
		{
			cnt-=(a[i]-a[l]);
			num--;
			l++;
		}
		ans=max(ans,(i-l+1));
		num++;
		
	}
	cout<<ans;
	return 0;
} 