#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

constexpr int N = 2e6+5;

int n;
ll d;
ll a[N];
ll ans=0;
int justt=1;
int cnt=0;

inline ll dfs(int l,int r,int cntt)
{
	ll sum=0;
	ll sum_=sum;
	if(cntt>cnt) return 0;
	if(l==r) return 1;
	for(int i=l+1;i<=r;++i)
	{
		if(a[i]-a[l]>d) return sum;
		sum+=dfs(i,r,cntt+1);
	}
	return sum;
}

inline void solve()
{
	ans=0;
	justt=1;
	cin >> n >> d;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	for(int i=1;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			justt=i;
			cnt=0;
			for(int k=i+1;k<=j;++k)
			{
				if(a[k]-a[k-1]>d) break;
				if(k==j)
				{
					if(a[k]-a[justt]>d)
					{
						cnt++;
					}
					cnt++;
				}
				else if(a[k]-a[justt]>d)
				{
					cnt++;
					justt=k-1;
				}
			}
			if(dfs(i,j,0)==2) 
			{
				ans++;
			}
		}
	}
	cout << ans << "\n"; 
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,T;
	cin >> c >> T;
	while(T--)
		solve();

	return 0;
}

