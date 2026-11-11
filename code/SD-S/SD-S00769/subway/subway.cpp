#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	cout << c + n + m + d + q << endl;
	cout << c + n + m + m + m << endl; 
	return 0;
}

