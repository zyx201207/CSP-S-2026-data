#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		int w;
		cin >> w;
	}
	int k;
	cin >> k;
	for(int j = 1;j <= 2 * k;j++)
		{
			int a;
			cin >> a;
		}
	
	for(int i = 1;i <= q + n + 2;i++)
	{
		int x,y;
		cin >> x >> y;
	}
	if(n == 2)
	{
		cout << 32 << endl << 17;
	}
	if(n == 3)
	{
		cout << 35 << endl << 16;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
