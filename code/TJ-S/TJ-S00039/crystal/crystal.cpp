#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
long long a[500005];
long long ans = -114514;

bool check(long long x,long long t,long long idx)
{
	long long cnt = 0;
	bool f = true;
	//cout << idx << endl;
	if(idx < 0)
	{
		return -1;
	}
	for(int i = idx;i >= 0;i--)
	{
		if((x - a[i]) <= t)
		{
		 	cnt++;
		 	t -= x - a[i];
		}
		else
		{
			f = false;
			break;
		}
	}
	ans = max(ans,cnt);
} 

int main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long ans1 = 1;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	for(int i = 1;i < n;i++)
	{
		if(a[i] == a[i - 1])
		{
			ans1++;
		}
		else
		{
			ans = max(ans,ans1);
			ans1 = 1;
		}
	}
	bool f = true;
	long long delta = a[1] - a[0];
	for(int i = 1;i < n;i++)
	{
		if(a[i] - a[i - 1] != delta)
		{
			f = false;
		}
	}
	ans = max(ans,ans1);
	long long cnt12 = 1;
	long long xi = 1;
	if(f)
	{
		//cout << "39428";
		delta = a[1] - a[0];
		while(m >= xi * delta)
		{
			m -= xi * delta;

			xi++;
			cnt12++;
		}
	
		if(cnt12 > n)
		{
			cout << n << endl;
			return 0;
		}
		cout << max(ans,cnt12);

		return 0;
	}
	long long l = 0;
	long long r = n - 1;
	for(int i = 0;i < n;i++)
	{
		check(a[i],m,i);
		//cout << i << ",";
	}
	cout << ans << endl;
	return 0;
 } 
