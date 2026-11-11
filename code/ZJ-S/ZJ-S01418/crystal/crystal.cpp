#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m;
const int N=500010; 
ll a[N];
ll sum, cnt;//代价与答案量 
ll l, r, mid;
ll ans, maxn = -1e18;
ll qian[N];
ll Isok(ll x, ll dec)
{
	ll vis = dec+1;
	sum = 0;
	cnt = 0; 
	l = 1, r = dec;
	while(l<r)
	{
		mid = (l+r)/2;
		if(qian[dec] - (qian[mid]+(mid-1)*(a[dec]-a[mid])) > m ) l = mid+1; 
		else r = mid;
//		cout << dec << " " << mid << " " << qian[dec] - (qian[mid]+(mid-1)*(a[dec]-a[mid])) << '\n'; 
	}
//	cout << "!!" << dec << " " << l << '\n';
	return dec-l+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);			//不要忘记打开！！！！！ 
	freopen("crystal.out","w",stdout);			//不要忘记打开！！！！！ 
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++)
	{
		qian[i] = qian[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout << qian[i] <<" "; 
	}
//	cout << '\n';
	for(int i = 1; i <= n; i++)
	{
		if(a[i+1] == a[i]) continue;
		else maxn = max(maxn, Isok(a[i],i));
	}
	cout << maxn;
	return 0;
}
