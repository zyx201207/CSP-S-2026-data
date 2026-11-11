#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n + 10];
	int f = 1;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		if(a[i] != i)
		{
			f = 0;
		}
	}
	sort(a + 1,a + n + 1);
	if(f == 1)
	{
		int s = 1;
		long long p[n + 10] = {};
		int tot = 1;
		for(int j = 1; j <= n - 1; j++)
		{
			p[tot++] = abs(a[j] - a[n]);
		}
		sort(p + 1,p + tot);
		for(int j = 1; j <= n - 1; j++)
		{
			if(m - p[j] >= 0)
			{
				//cout<<"p[j] = "<<p[j]<<" "<<"m = "<<m<<endl;
				m -= p[j];
				s++;
			}
		}
		cout<<s<<endl;
		return 0;
	}
	int t = 0;
	long long mm = m;
	for(int i = 1; i <= n; i++)
	{
		//cout<<a[i]<<":"<<endl;
		int s = 1;
		long long p[n + 10] = {};
		int tot = 1;
		for(int j = 1; j <= i - 1; j++)
		{
			p[tot++] = abs(a[j] - a[i]);
		}
		sort(p + 1,p + tot);
		for(int j = 1; j <= i - 1; j++)
		{
			if(m - p[j] >= 0)
			{
				//cout<<"p[j] = "<<p[j]<<" "<<"m = "<<m<<endl;
				m -= p[j];
				s++;
			}
		}
		t = max(t,s);
		m = mm;
		//cout<<"s = "<<s<<" t = "<<t<<endl;
	}
	cout<<t<<endl;	
	
	return 0;
}
