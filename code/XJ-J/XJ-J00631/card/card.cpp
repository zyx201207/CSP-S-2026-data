#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,a[100001];
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << n << a[0] << m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}