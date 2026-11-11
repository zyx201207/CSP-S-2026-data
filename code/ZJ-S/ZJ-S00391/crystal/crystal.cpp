#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	queue<int>q;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	q.push(a[0]);
	for(int i=1;i<n;i++)
	{
		sum+=q.size()*(a[i]-a[i-1]),q.push(a[i]);
		while(sum>m)sum-=a[i]-q.front(),q.pop();
		ans=max(ans,(int)q.size());
	}
	return cout<<ans,0;
}