#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long a[maxn],m,sum[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1; i <= n; i++)	sum[i] = sum[i - 1] + a[i];
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j <= i - 3; j++)
		{
			if((i - j) * a[i] - (sum[i] - sum[j]) <= m)
			{
				cout << i - j;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}//»áT 
