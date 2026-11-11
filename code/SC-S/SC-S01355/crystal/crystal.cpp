#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
long long ans=0;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long last=0;
	for(long long i=1;i<=n;i++)//枚举i,找最多可以将前面多少个变为a[i]
	{
		while(sum[i-1]-sum[last]+m<1ll*(i-last-1)*a[i])//离i约近花费越少
		{
			last++;
		}
		ans=max(ans,i-last);
//		cout<<last<<" "<<i<<"----\n";
	}
	cout<<ans;
	return 0;
}
//相同的数量离i约近，花费越少