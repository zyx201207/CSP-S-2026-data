#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string a;
	int n,k,m=0;
	char p;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> k >> p;
		for (int j=1; j<=k; j++)
		{
			a += p;
		}
	}
	for (int i=1; i<=a.size(); i++)
	{
		if (a[i] == a[i-1])
		{
			m++;
		}
	}
	if (a[0] == a[a.size()-1])
	{
		m = 0;
	}
	cout << m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}