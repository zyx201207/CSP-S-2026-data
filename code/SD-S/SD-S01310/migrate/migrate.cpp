#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 2e6+10;
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
int a[N],x[N],dp[N],f[N];
int cnt[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(),T = read();
	if(c == 11 || c == 12)
	{
		while(T--)
		{
			int n = read(),d = read();
			for(int i = 1;i<=n;++i)
				a[i] = read();
			int diff = a[n]-a[n-1];
			int c = d/diff;
			if(c == 0)
				cout<<0<<endl;
			else
				cout<<n-c<<endl; 
		}
		return 0;
	}
	while(T--)
	{
		int n = read(),d = read();
		for(int i = 1;i<=n;++i)
		{
			a[i] = read();
			int l = 1,r = i-1;
			x[i] = n+1;
			while(l <= r)
			{
				int mid = (l+r)>>1;
				if(a[i] - a[mid] <= d)
				{
					x[i] = mid;
					r = mid-1;
				}
				else l = mid+1;
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;++i)
		{
			dp[i] = 0;
			for(int j = i+1;j<=n;++j)
				dp[j] = dp[max(i,x[j])]+1;
			for(int j = 1;j<=n;++j)
			{
				cnt[j] = 0;
				f[j] = 0;
			}
			f[i] = 1;
			int k = i;
			cnt[dp[k]] = f[k];
			for(int j = i+1;j<=n;++j)
			{
				while(k < x[j])
				{
					cnt[dp[k]] -= f[k];
					k++;
				}
				f[j] = cnt[dp[j]-1];
				cnt[dp[j]] += f[j];
				if(f[j] == 2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

