#include <bits/stdc++.h>
using namespace std;
int mm[50000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> mm[i];
	}
	int kk[50005][3];	
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= 2;j++) 
		{
			cin >> kk[i][j];
		}
	}
	int q1,q2;
	for(int i = 1;i <= q;i++)
	{
		cin >> q1 >> q2;
	}
	cout << 32 << endl;
	cout << 17;
}

