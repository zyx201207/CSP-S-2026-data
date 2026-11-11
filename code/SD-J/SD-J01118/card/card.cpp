#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int k = 1;k <=n;k++)
	{
		cin >> a[k];
	}
	for(int k = 1;k <= n;k++)
	{
		for (int i = k+1;i <= n;i++)
		{
			b[i] = a[i];
		}
	}
	return 0;
}
