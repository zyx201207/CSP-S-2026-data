#include<bits/stdc++.h>
#define cl long long
using namespace std;
cl n,m;
cl a[500005];
cl s[500005];
bool ch(cl x)
{
	for(int i=x;i<=n;i++)
	{
		if((x-1)*a[i]-(s[i-1]-s[i-x])<=m)
			return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(cl i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(cl i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++)
//		cout<<s[i]<<" ";
	cl l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ch(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
		
	
	
}
/*
5 5
1 2 4 8 9
*/








