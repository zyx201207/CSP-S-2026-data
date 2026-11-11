#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005],ans;
bool check(int i,int x)
{
	if((i-x)*a[i]-(s[i-1]-s[x-1])<=m)return 1;
	else return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))r=mid;
			else l=mid+1;
		}
		ans=max((i-r+1)*1ll,ans);
	}
	cout<<ans;
	return 0;
}
