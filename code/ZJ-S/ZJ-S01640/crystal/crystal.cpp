#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,p=1,cur=0;
	for(int i=1;i<=n;i++)
	{
		cur+=(i-p)*(a[i]-a[i-1]);
		while(cur>m)
			cur-=a[i]-a[p],p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans<<"\n";
}