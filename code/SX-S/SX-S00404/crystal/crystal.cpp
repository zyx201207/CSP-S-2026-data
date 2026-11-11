#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],sum[N],pos,ans;
bool check(int wz,int e)
{
	int tmp = sum[e] - sum[wz - 1] - (e - wz + 1) * (a[n] - a[e]);
	return tmp <= m;
}
int ef(int x)
{
	int l = 1,r = x,mid,res = x;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(check(mid,x)) res = mid,r = mid - 1;
		else l = mid + 1;
	}
	return res;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for1(1,n,i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for1(1,n,i)
	{
		sum[i] = a[n] - a[i];
		sum[i] += sum[i - 1];
	}
	for1(1,n,i)
	{
		pos = ef(i);
		ans = max(ans,i - pos + 1);
	}
	cout << ans;
	return 0;
}
