#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,ans;
queue <int> q;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	q.push(a[1]);ans=1;
	for(int i=2;i<=n;i++)
	{
		cnt+=q.size()*(a[i]-a[i-1]);
		q.push(a[i]);
		while(cnt>m)
		{
			int p=q.front();
			q.pop();
			cnt-=(a[i]-p);
		}
		int size=q.size();
		ans=max(ans,size);
	}
	cout<<ans<<endl;
	return 0;
}
