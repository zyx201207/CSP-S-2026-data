#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005];
void dfs(long long dep, long long num, long long cnt)
{
	if (cnt==m) {ans=max(ans,num); return;}
	if (dep==n) return;
	dfs(dep+1,num,cnt);
	dfs(dep+1,num&a[dep+1],cnt+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1; i<=n; i++) cin>>a[i];
	if (n>2000)
	{
		sort(a+1,a+1+n);
		ans=a[n-m+1];
	}
	else if (m==1)
	{
		sort(a+1,a+1+n);
		ans=a[n];
	}
	else if (m==2)
		for (int i=1; i<n; i++)
			for (int j=i+1; j<=n; j++)
				ans=max(ans,(a[i]&a[j]));
	else if (m==n)
    {
    	ans=a[1];
    	for (int i=2; i<=n; i++) ans=ans&a[i];
	}
	else dfs(0,pow(2,12)-1,0);
	cout<<ans;
	return 0;
}