//王子政 SN-J00825 西安市益新中学
#include <bits/stdc++.h>
using namespace std;
int a[50025];
map <int,int>aa;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if (n==1)
	{
		cout << 1;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	map <int,int> aa;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j=n;j++)
		{
			aa[a[j]]++;
		}
	}
	for (auto x : aa)
	{
		cout << x;
	}
}
