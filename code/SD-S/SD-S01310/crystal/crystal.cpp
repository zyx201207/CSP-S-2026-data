#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 5e5+10;
using namespace std;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x*10+ch-'0',ch = getchar();
	return x*f;
}
int a[N],sum[N];
int n,k;
bool check(int x)
{
	for(int i = x;i<=n;++i)
	{
		if(a[i]*x - (sum[i]-sum[i-x]) <= k)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i<=n;++i)
		a[i] = read();
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;++i)
		sum[i] = sum[i-1]+a[i];
	int l = 1,r = n;
	int ans = 0;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
