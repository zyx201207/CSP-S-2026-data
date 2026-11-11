#include <bits/stdc++.h>
using namespace std;
int a[500001]={0},b[500001];
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	cout << n << " " << a[1] << " " << m;
	return 0;
}
