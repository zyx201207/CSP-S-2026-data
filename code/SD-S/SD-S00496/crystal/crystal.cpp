#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,cnt=1,ans=1;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		m=m-(a[i]-a[i-1])*cnt;
		while(1)
		{
			if(m>=0) break;
			m+=a[i]-a[i-cnt];
			cnt--;
		}
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
 }

