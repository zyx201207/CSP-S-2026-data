

#include<bits/stdc++.h>
#define int long long
// #define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans=0;
bool chk(int id)
{
	int maxn=m,ans1=0;
	for(int i=id;i>=1;i--)
	{
		if(maxn>=(a[id]-a[i]))
		{
			maxn-=(a[id]-a[i]);
			ans1++;
		}
		else {
			ans=max(ans,ans1);
		}
	}
	if(ans1<ans)return 0;
	else 
	{
		ans=ans1;
		return 1;
	}
}
int flag=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)flag=1;
	}
	sort(a+1,a+n+1);
	if(flag==0)
	{
		int x=m;
		x*=2;
		int sqt=(sqrt(x));
		if(sqt*(sqt+1)<x)cout<<min(sqt,n);
		else cout<<min(sqt+1,n);
		// cout<<min(sqt+1,n)<<'\n';
		return 0;
		
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			chk(i);
		}
		cout<<ans;
	}
	else 
	{
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(chk(mid))l=mid+1;
			else r=mid-1;
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/
