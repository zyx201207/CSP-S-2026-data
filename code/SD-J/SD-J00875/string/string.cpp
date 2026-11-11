#include<bits/stdc++.h>
using namespace std;
long long mid = 0 , n;
struct lt
{
	int a;
	char c;
}w[int(2e5 + 5)];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i = i + 1)
	{
		cin >> w[i].a >> w[i].c;
		mid = mid + w[i].a;
	}
	long long cnta = 0 , cntb = mid;
	mid = mid / 2;
	long long l = 1 , r = n , ans = 0;
	long long cnt1 = w[l].a , cnt2 = w[r].a;
	while(cnta <= mid && cntb > mid)
	{
		if(cnt1 > cnt2)
		{
			cnta = cnta + cnt2;
			cntb = cntb + cnt2;
			cnt1 = cnt1 - cnt2;
			if(w[l].c != w[r].c)
			{
				ans = ans + cnt2;
			}
			cnt2 = 0;
		}
		else if(cnt1 < cnt2)
		{
			cnta = cnta + cnt1;
			cntb = cntb + cnt1;
			cnt2 = cnt2 - cnt1;
			if(w[l].c != w[r].c)
			{
				ans = ans + cnt1;
			}
			cnt1 = 0;
		}
		else
		{
			cnta = cnta + cnt2;
			cntb = cntb - cnt2;
			if(w[l].c != w[r].c)
			{
				ans = ans + cnt1;
			}
			cnt1 = 0 , cnt2 = 0;
		}
		if(cnt1 == 0)
		{
			l = l + 1;
			cnt1 = w[l].a;
		}
		if(cnt2 == 0)
		{
			r = r - 1;
			cnt2 = w[r].a;
		}
	}
	cout << ans;
	return 0;
}
