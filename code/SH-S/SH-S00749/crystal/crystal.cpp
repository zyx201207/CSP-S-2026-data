#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD=INT_MAX;
const int MAXN=5e5;
int n;
ll m,a[MAXN+5],sum[MAXN+5];

bool ok(int k)
{
	for (int l=1;l+k-1<=n;l++)
	{
		int r=l+k-1;
		if (1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1])<=m)
			return 1;
	}
	return 0;
}
int find()
{
	int l=1,r=n,ans=1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (ok(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}

void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if (n<=5000)
	{
		int ans=1;
		for (int i=1;i<=n;i++)
		{
			int num=0;
			ll cnt=0;
			for (int j=n;j>=1;j--)
			{
				if (a[j]<=a[i])
				{
					if (cnt+(a[i]-a[j])<=m)
					{
						cnt+=(a[i]-a[j]);
						num++;
					}
					else break;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;
	}
	else cout<<find();
	return 0;
}
