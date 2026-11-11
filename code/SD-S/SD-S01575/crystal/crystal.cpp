#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<=b;i++)
#define eb emplace_back
#define ll long long
const int N=1e6+5;
ll n,m,a[N],s[N],ans;
/*
5 8
-3 -1 2 2 7

14:50
*/
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	For(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	For(i,1,n)s[i]=s[i-1]+a[i];
	For(i,1,n)
	{
		ll l=i,r=n,res=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(a[mid]*(mid-i+1)-s[mid]+s[i-1]<=m)res=mid,l=mid+1;
			else r=mid-1;
		}
		//cout<<res<<' ';
		ans=max(ans,res-i+1);
	}
	cout<<ans;
	return 0;
}

