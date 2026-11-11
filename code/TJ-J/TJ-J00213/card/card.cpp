//card
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans[50005];
	cin >> n >> m;
	int a[50005];
	for (int i = 1; i <= n; i++)//ÊäÈë 
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cout << i + i<< " ";
	}
	return 0;
} 
