#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
bool check(int x)
{
	int t=m;
	for(int i=1;i<=x;i++)
	{
		t=t-(a[x]-a[i]);
		if(t<0)return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,s=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,s=mid;
		else r=mid-1;
	}
	while(a[s+1]==a[s])s++;
	cout<<s;
	return 0;
}
