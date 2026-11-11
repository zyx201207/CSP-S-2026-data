#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	long long w[150000];
	unsigned long long sum = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		sum = 0;
		cin >> w[i];
		sum += w[i];
	}
	cout << sum;
	return 0;
}
