#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
ll a[maxn],pre[maxn];
ll Query(int l,int r)
{
	return pre[r]-pre[l-1];
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,p=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*(1ll*i-1ll*mid+1ll)-Query(mid,i)<=m)
			{
				p=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
//		cout<<i-p+1<<' ';
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
//shaqu feiqu jianqu
