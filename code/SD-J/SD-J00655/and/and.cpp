#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5;
long long a[MX + 10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,i;
	cin >> n >> k;
	for(i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,greater<int>());
	for(i = 1;i < k;i++)
	{
		if((a[i] & a[i + 1]) == 0)
		{
			k++;
		}
		else
		{
			a[i] & a[i + 1];
		}
	}
	cout << a[k] << '\n';
	return 0;
}
