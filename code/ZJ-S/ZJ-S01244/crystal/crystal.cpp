#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5;
long long n,m,a[N+10],pre[N+10];
bool check(long long x)
{
	for(int i = 1; i+x-1 <= n; i++)
	{
		//[i,i+x-1]
		if(a[i+x-1]*x-(pre[i+x-1]-pre[i-1])<=m)    return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)    cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++)    pre[i] = pre[i-1]+a[i];
	long long l1 = 1, r1 = n,ans1 = -1;
	while(l1<=r1)
	{
		long long mid = (l1+r1)/2;
		if(check(mid))
		{
			ans1 = mid;
			l1 = mid+1;
		}
		else    r1 = mid-1;
	}
	cout << ans1;
	return 0;
}
