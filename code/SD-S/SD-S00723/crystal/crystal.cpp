#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll read()
{
	char ch = getchar();
	ll num = 0,sign = 1;
	while(ch<'0'||ch>'9')sign = (ch == '-'?-1:1),ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+(ch-'0'),ch = getchar();
	return sign>0?num:-num;
}
const int N = 5e5+8;
ll n,m,a[N],dif[N],sum[N],ans = 1;
bool check(ll lft,ll max)
{
	ll ans = sum[max]-sum[lft-1]-1ll*(max-lft+1)*dif[max];
	if(ans <= m)return 1;
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++)a[i] = read();
	sort(a+1,a+n+1);
	for(int i = n-1;i >= 1;i--)dif[i] = a[n]-a[i];
	for(int i = 1;i <= n;i++)sum[i] = sum[i-1]+dif[i];
	for(int i = 1;i <= n;i++){
		ll l = 1,r = i;
		while(l < r)
		{
			int mid = (l+r)>>1;
			if(check(mid,i))r = mid;
			else l = mid+1;
		}
		ans = max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

