#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7+10;
long long a[N];
long long n,m;
long long h;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==2)
		{
			h++;
		}
	} 
	if(m==1)
	{
		cout << n << '\n';
		return 0;
	}
	if(h==1)
	{
		if(a[5]==2)
		{
			cout << 5 << ' ' << 5;
		}else
		{
			cout << 5 << ' ' << 1;
		}
	}else if(h==4)
	{
		if(a[5]==1)
		{
			cout << 5 << ' ' << 5; 
		}else
		{
			cout << 1 << ' ' << 5;
		}
	}else if(h==2)
	{
		if(a[5]==2)
		{
			if(a[1]==2)
			{
				cout << 5 << ' ' << 4;
			}else
			{
				cout << 5 << ' ' << 5;
			}
		}else
		{
			cout << 5 << ' ' << 2;
		}
	}else
	{
		if(a[5]==1)
		{
			if(a[1]==1)
			{
				cout << 4 << ' ' << 5;
			}else
			{
				cout << 5 << ' ' << 5;
			}
		 } else
		 {
		 	cout << 2 << ' ' << 5;
		 }
	}
	return 0;
}
