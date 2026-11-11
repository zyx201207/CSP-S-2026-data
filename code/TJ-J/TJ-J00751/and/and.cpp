#include <bits/stdc++.h>
using namespace std;
struct str
{
	string p;
};
char kcap[100];
string pack;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	str pack_[20005];
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[200005],b[200005];
	long long n,m;
	cin >> n >> m;
	int max1 = -1;
	long long o = 1,maxest;
	for (int i=1;i<=31;i++)
	{
		o *= 2;
	}
	o-=1;
	long long num = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (m == 1)
		{
			if (a[i] > max1)
			{
				max1 = a[i];
			}
		}
		else if (m == n)
		{
			o = a[i] & o;
		}
		else if (m == 2)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=i;j<=n;j++)
				{
					b[i] = a[i] & a[j];
				} 
			}
			for (int i=1;i<=n;i++)
			{
				if (b[i] > max1)
				{
					max1 = b[i];
				}
			 } 
		}
	}
		if (m == 1)
		{
			cout << max1;
		}
		else if (m == n)
		{
			cout << o;
		}
		else if (m == 2)
		{
			cout << max1;
		}
	return 0;
}
