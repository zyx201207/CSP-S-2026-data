#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],diff[N],sum[N];
bool check(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		int l=i,r=i+len-1;
		if(m+sum[r]-sum[l-1]>=a[r]*len)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i]; 
	}
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)==true)
		{
			l=mid;
		}	
		else
		{
			r=mid;
		}
	} 
	if(l==1)
	{
		cout<<0<<"\n";
		return 0;
	}
	cout<<l<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3-1 2 2 7
500,000
*/
