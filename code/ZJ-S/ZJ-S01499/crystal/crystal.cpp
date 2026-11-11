#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
long long n,m,a[MAXN],diff[MAXN],cost[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++) cost[i]=cost[i-1]+diff[i]*(i-1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(n-i+1<ans) break;
		int j=1;
		while(cost[j]-(a[j]-a[i])<=m) j++;
		j--;
		ans=max(ans,1ll*(j-i+1));
	}
	cout<<ans;
	return 0;
}

