#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
long long n,m,l,r,ans;
bool flag;
long long a[500050];
long long b[500050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i = 1;i <= n;i++)
		b[i] = b[i-1]+a[i];
	l = 1;
	r = n;
	ans = 1;
	while(l <= r)
	{
		long long mid = ((r-l)>>1)+l;
		flag = false;
		for(long long i = mid;i <= n;i++)
			if(m >= a[i]*mid-b[i]+b[i-mid])
			{
				flag = true;
				break;
			}
		if(flag)
		{
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
//long long long long
//cin 
