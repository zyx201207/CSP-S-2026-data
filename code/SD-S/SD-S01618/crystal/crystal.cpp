#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
long long n,m,ansa;
long long check(long long num)
{
	int l=1,r=num,ans;
	while(l<=r)
	{
		int mid=(l+r)/2; 
		if(a[num]*(num-mid+1)-(s[num]-s[mid-1])<=m)
		{
			r=mid-1;
			ans=num-mid+1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ansa=max(ansa,check(i));
	}
	cout<<ansa;
	return 0;
}
