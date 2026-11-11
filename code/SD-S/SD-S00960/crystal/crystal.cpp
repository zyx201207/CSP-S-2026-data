#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],sum[N],maxx=-0x3f3f3f3f;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	for(int i=1;i<n-maxx;i++)
	{
		int cnt=0,l=0,wei=i;
		while(cnt<=m && wei<=n)
		{
			wei++;
			cnt=(wei-1)*a[wei]-sum[wei-1];
			if(cnt>m)
			{
				break;
			}
			l++;
		}
		maxx=max(maxx,l+1);
	}
	cout<<maxx;
	return 0;
}
