#include<bits/stdc++.h>
using namespace std;
int n , m , a[500005] , maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= m;i++)
	{
		a[1]++;
		sort(a + 1,a + n + 1);
		int cnt = 1;
		for(int i = 2;i <= n;i++)
		{
			if(a[i] == a[i - 1])
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		maxn = max(maxn , cnt);
	}
	cout << maxn << endl;
	return 0;
}
