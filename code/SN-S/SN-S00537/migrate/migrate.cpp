#include <bits/stdc++.h>
using namespace std;
struct B
{
	int x;
	int l;
};
B a[2000001];
int main()
{
//	freopen("migrate1.in", "r", stdin);
//	freopen("migrate1.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].x;
		}
		int cnt = 0, sum = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(abs(a[i].x-a[j].x) < (j-i)*d && abs(j-i) >= 3)
				{
					
				}
			}
		}
		cout << cnt;
	}
	return 0;
}
