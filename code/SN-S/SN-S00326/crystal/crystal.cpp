//高一轩 西安铁一中滨河高级中学 SN-S0036 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ii;
/*	int gcd(int x,int y){return y ? gcd(y,x%y) : x;}
	queue <int> s;*/
long long P(long long x)
{
	long long o = 0;
	for(long long i = ii;i<x;i++)
	{
		o += a[x] - a[i];
	}
	return o <= m;
}
long long find(long long l,long long r)
{
	long long ans = 0;
	while(l<=r)
	{
		long long mid = (l + r) >> 1;
		//cout << mid << l << r << "\n";
		if(P(mid))
		{
			ans = mid;l = mid + 1;
		}
		else
		{
			r = mid -1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n>> m;
	for(long long i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 0;
	int i1;
	for(;ii<n-1;ii++)
	{
		if(find(ii,n-1) - ii>ans)
			ans = find(ii,n-1) - ii;
	}
	cout << ans + 1;
	return 0;
	/*记得long long,文件注释*/
}
