//shuijing
#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	long long m;
	int n ,ans = 0,tempans = 0;
	cin >> n >> m;
	int a[75000],cha[75000];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if (n <= 74999)
	{
		long long conm = m;
		sort(a+1,a+1+n);
		for (int i = 1; i <= n; i++)
		{
			//cout << i;
			for (int j = i; j >= 1; j--)
			{
				cha[i-j+1] = abs(a[i] - a[j]);
			} 
			sort(cha+1,cha+i+1);
			/*for (int j = 1; j <= i; j++)
			{
				cout <<" "<<cha[j] << " ";
			}*/
			//cout <<endl;
			for (int j = 1; j <= i; j++)
			{
				if(m < cha[j]) break;
				else {m -= cha[j]; tempans++;}

			}
			ans = max(ans,tempans);
			tempans = 0;
			m = conm;
		}
	}
	else
	{
		int dengcha = a[2] - a[1];
		long long chashu = m / dengcha;
		int j = 0;
		while (chashu >= j)
		{
			chashu -= j;
			ans++;
			j++;
		}
	}
	cout << ans ;
	
	return 0;
}
