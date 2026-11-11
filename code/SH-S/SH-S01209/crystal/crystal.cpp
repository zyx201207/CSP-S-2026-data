#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,a[N],s[N];
bool check(int x) 
{
	for(int j=x;j<=n;j++)
	{
		int i=j-x+1;
		int sum=s[j]-s[i-1];
		if(a[j]*x-sum<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
