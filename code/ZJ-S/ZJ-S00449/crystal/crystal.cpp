#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxa,s[500005];
int ans;
bool cmp(long long x,long long y)
{
	return x<y;
}
bool check(int x,int y)
{
	if((a[y]*(y-x+1)-s[y]+s[x-1])<=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i-mid+1,i))
			{
				ans=max(ans,mid);
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<ans;
 	return 0;
}