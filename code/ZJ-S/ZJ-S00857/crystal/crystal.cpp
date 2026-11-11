#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//  don't forget long long!
// 	don't forget cheak cpp!
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l = 1;
	long long r = 1;
	long long ans = 1;
	long long sum = 0;
	while(r<=n)
	{
		sum += (a[r]-a[r-1])*(r-l);
		if(sum<=m) ans = max(ans,r-l+1);
		else 
		{
			while(l<=r&&sum>m) 
			{
				sum -= a[r]-a[l];
				l++;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}
/*
I hope AC
*/
