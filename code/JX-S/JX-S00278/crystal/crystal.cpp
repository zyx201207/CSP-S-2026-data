#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;

long long s[500005];
long long a[500005];
long long m;
int n;

bool check(int l,int r)
{
	long long sum=s[r]-s[l-1];
	long long res=1LL*(r-l+1)*a[r]-sum;
	return res<=m;
}

signed main()
{
#ifndef _WJW_LOCAL_JUDGE
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}
// if(ans<i-l+1)
// cerr<<"Update ans: "<<ans<<" -> "<<i-l+1<<", i="<<i<<", l="<<l<<", n="<<n<<'\n',sleep(500);
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}