#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
const int N = 5e5+10;
const int M = 1e5;
int n,a[N],m,z,w,b[250],l = 1,f;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] += M;
	}
	for (int i = 2;i <= n;i++)
	{
		if (a[i]-a[i-1] == a[2]-a[1]) f++;
	}
	if (f == n-1)
	{
		int t = a[2]-a[1];
		for (int i = 1;i <= n;i++)
		{
			w += (i-1)*t;
			if (m <= w)
			{
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++)
	{
		w = 0;
		for (int j = i;j >= l;j--)
		{
			w += abs(a[j]-a[i]);// 累计判断是否需要移动左端点的数 
//			if (z == 4) cout << (i-(j-1));
			if (w > m)//移动左端点 
			{
				l = j;
				break;
			}
			z = max(z,(i-(j-1)));//统计最大区间 
		}
	}
	cout << z;
	return 0;
}
/*
5 8
-3 -1 2 2 7
6 6 
0 4 8 9 10 13
*/
