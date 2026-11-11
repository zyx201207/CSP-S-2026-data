#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005],ans,ta,gs,pans;
bool ab = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long usu;
	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
		if(i > 0 && ab)
		{
			if(a[i] - a[i-1] != usu)ab = 0;
		}
		else if(i==0)usu = a[i]-a[i-1];
	}
	if(!ab)
	{
		sort(a,a+n);
		for(int i = 0; i< n; i++)
		{
			gs += a[i];
		}
		gs /= n;
		int pp = 0;
		while(a[pp] < gs)
		{
			pp++;
		}
		int ap = a[pp];
		while(a[pp] == ap)
		{
			pp++;
		}
		pp--;
		for(int i = 0; i < n/10+2; i++)
		{
			long long mis = 0;
			int go = 1;
			pans = 1;
			while(mis <= m && pp+i-go >= 0)
			{
				pans++;
				mis += a[pp+i] - a[pp+i-go];
				go++;
			}
			ans = max(pans,ans);
			mis = 0; go=1;pans=1;
			while(mis <= m && pp-i-go >= 0)
			{
				pans++;
				mis += a[pp-i] - a[pp-i-go];
				go++;
			}
			ans = max(pans,ans);
		}
	}
	else
	{
		long long go = 1;
		ans = 1;
		while(m >= 0 && go < n)
		{
			m -= go * usu;
			go++;ans++;
		}
		if(m<0)ans--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
