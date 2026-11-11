#include <bits/stdc++.h>
using namespace std;
int a[500005];
int wxy[500004];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int  m_forever = m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	for(int i = 2;i <= n;i++)
	{
		m = m_forever;
		int sum = 0;
		for (int j = i-1;j > 0;j--  && m >= 0)
		{
			int rty = a[i] - a[j];	
			m -= rty;
			if (m >= 0)
			{
				sum += 1;
			}
			
		}
		wxy[i] = sum;
	} 
	sort(wxy+2,wxy+n+1);
	cout << wxy[n]+1;
}

