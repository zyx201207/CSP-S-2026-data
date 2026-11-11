#include <bits/stdc++.h>
using namespace std;
long long n,b=0,t=0,cnt=0;
char c;
string a;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> b >> c;
		for (int j=1;j<=b;j++)
			a+=c;
		t+=b;
	}
	for (int i=0;i<t/2;i++)
	{
		if (a[i]!=a[t-i-1])
			cnt++;
	}
	cout << cnt;
	return 0;
}
