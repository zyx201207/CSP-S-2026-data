#include <bits/stdc++.h>
using namespace std;
char q[10000005],y;
long long n,x,ans,r = 1;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x >> y;
		for(int j = 1;j <= x;j++)
		{
			q[r] = y;
			++r;
		}
	}
	for(int i = 1;i <= (r - 1) / 2;i++)
	{
		if(q[i] != q[r - 1])
			ans++;
		r -= 1;
	}
	cout << ans;
}
