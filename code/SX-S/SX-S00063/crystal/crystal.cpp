#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
ll n,lkm,ans=-1e18;
ll a[N];
//bool cmp(ll x,ll y)
//{
//	return x<y;
//}
ll check(ll k)
{
	ll sum=0,m=lkm;
	for(int i=1;i<=n;i++)
	{
		if(a[k]<a[i]) continue;
		if(m<(a[k]-a[i])) continue;
		else
		{
			sum++;
			m-=(a[k]-a[i]);
		}
	}
	return sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>lkm;//二分
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//mmax=max(mmax,a[i]);
	}
	sort(a+1,a+n+1);
	ll l=0,r=n;
	ll mid;
	while(l<=r)
	{
		mid=((l+r)/2);
		ll tmp=check(mid);
		if(tmp>=ans)
		{
			ans=tmp;
			l=mid+1;
		}
		else 
		{
			r=mid-1;
		}
	}
	mid=(l+r)/2;
	cout<<max(check(mid),ans);
	return 0;
}
//long year OI is gunmu
//no opening long long meet grandpa's grandpa 
//为啥一直不过最后一个大样例啊？
//加油！
//我们绝不投降！
//
//我真的燃尽了。
//kards ID:鼠鼠军团#2949
//luogu:turing_wanba