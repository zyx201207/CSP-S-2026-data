#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int ans=1,sum=0;
	queue <int> q;
	q.push(a[1]);
	for(int i=2;i<=n;i++)
	{
		if(q.empty()) q.push(a[i]);
		else
		{
			int x=a[i-1];
			int hf=a[i]-x;
			int l=q.size();
			sum+=l*hf;
			q.push(a[i]);
			while(sum>m)
			{
				int xx=q.front();
				q.pop();
				sum-=a[i]+xx;
			}
			int ll=q.size();
			ans=max(ans,ll);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
