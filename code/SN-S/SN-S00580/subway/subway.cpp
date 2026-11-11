#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[100005],k,x,y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	int a = 0,b = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> x >> y;
			a += x;
			b += y;
		}
	}
	cout << b << "\n" << a;
	return 0;
}
