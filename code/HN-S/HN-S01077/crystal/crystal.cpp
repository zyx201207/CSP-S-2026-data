#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,ans;
int l=2e18;
int r=-2e18;
int a[N]; 
bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)
		{
			sum+=x-a[i];
		}
		else break;
	}
	return sum<=m;
}	
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(a[i],l);
		r=max(a[i],r);
	}
	sort(a+1,a+1+n);
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	int cnt=l;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>cnt)
		{
			ans=i-1;
			break;
		}
	} 
	cout<<ans;
	return 0;
}
