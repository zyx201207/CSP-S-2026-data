#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e5+10;
int a[N];
int sum[N];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; cin >>n >>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0,idx=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-idx+1)-(sum[i]-sum[idx-1])>m) idx++;
		ans=max(ans,i-idx+1);
	}
	cout <<ans;
	return 0;
}