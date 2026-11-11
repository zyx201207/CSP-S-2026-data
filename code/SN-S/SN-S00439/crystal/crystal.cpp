//SN-S00439 西安市铁一中 蒋雨曦 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 500005 
using namespace std;
ll n,m,a[maxn],ans,sum[maxn];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
	cin>>n>>m; for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<i)
		{
			ll x=sum[i]-sum[now-1];
			if(a[i]*(i-now+1)-x<=m) break;
			now++;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
	return 0;
}
