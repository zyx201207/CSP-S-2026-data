#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l,ans;
char c[200005];
long long la[200005],ra[200005],m;
char lc[200005],rc[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
	}
	m = l/2;
	long long k = m;
	int i = 1;
	while(k)
	{
		if(k >= a[i])
		{
			k -= a[i];
			la[i] = a[i];
			lc[i] = c[i];
			i++;
		}
		else
		{
			la[i] = k;
			k = 0;
			lc[i] = c[i];
			i++;
		}
	}
	k = m;
	i = n;
	while(k)
	{
		if(k >= a[i])
		{
			k -= a[i];
			ra[i] = a[i];
			rc[i] = c[i];
			i--;
		}
		else
		{
			ra[i] = k;
			k = 0;
			rc[i] = c[i];
			i--;
		}
	}
	/*
	int lk=0,rk=0;
	for(int i = 1;i <= n;i++)
	{
		cout << la[i] << lc[i] << "|" << ra[i] << rc[i] << endl;
		lk += la[i];
		rk += ra[i];
	}
	cout << lk << "|" << rk << endl;
	*/
	int li = 1,ri = n;
	while(li <= n && ri >= 1)
	{
		//cout << li << "^" << ri << "+++" << lc[li] << "-" << rc[ri] << "no" << la[li] << "|" << ra[ri] << "#####";
		if(lc[li] == rc[ri])
		{
			if(la[li] >= ra[ri])
			{
				la[li] -= ra[ri];
				ra[ri] = 0;
			}
			else
			{
				ra[ri] -= la[li];
				la[li] = 0;
			}
		}
		else
		{
			if(la[li] >= ra[ri])
			{
				la[li] -= ra[ri];
				ans += ra[ri];
				ra[ri] = 0;
			}
			else
			{
				ra[ri] -= la[li];
				ans += la[li];
				la[li] = 0;
			}
		}
		//cout << la[li] << "|" << ra[ri] << "yes" << ans << endl;
		if(la[li] == 0)
			li++;
		if(ra[ri] == 0)
			ri--;
	}
	cout << ans;
	return 0;
} 
