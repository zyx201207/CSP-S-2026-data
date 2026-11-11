#include <bits/stdc++.h>
using namespace std;
int a,x[1000005],ans=0;
char n[1000005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a;
	for (int i = 1;i <= a;i++)
	{
		cin >> x[i] >> n[i];
	}
	for (int i = 1;i <= a%2;i++)
	{
		if (n[i] != n[a-i+1])
		{
			ans += x[a-i+1];
		}
	}
	cout << ans;
}
