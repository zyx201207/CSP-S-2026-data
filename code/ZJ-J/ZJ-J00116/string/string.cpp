#include<bits/stdc++.h>
using namespace std;
struct N
{
	long long num;
	char val;
}a[200022];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ms = 0,sum = 0,id = 1,jd = 0,ans = 0; cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].val;
		ms += a[i].num;
	}
	ms /= 2; jd = n;
	while(sum+a[id].num <= ms)
	{
		if(a[id].val != a[jd].val)
		{
			if(a[id].num > a[jd].num)
			{
				ans += a[jd].num; sum += a[jd].num;
				a[id].num -= a[jd].num; a[jd].num = 0;
				jd--;
			}
			else if(a[id].num == a[jd].num)
			{
				ans += a[id].num; sum += a[id].num;
				a[id].num = 0; a[jd].num = 0;
				id++; jd--;
			}
			else
			{
				ans += a[id].num; sum += a[id].num;
				a[jd].num -= a[id].num; a[id].num = 0;
				id++;
			}
		}
		else
		{
			long long t = min(a[id].num,a[jd].num);
			sum += t; a[id].num -= t; a[jd].num -= t;
			if(a[id].num == a[jd].num)id++,jd--;
			else if(a[id].num == 0)id++;
			else jd--;
		}
	}
	for(long long i = jd;i > id;i--)
	{
		ans += a[jd].num;
	}
	cout << ans << "\n";
	return 0;
}//string
