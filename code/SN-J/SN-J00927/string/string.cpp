#include<bits/stdc++.h>
using namespace std;
int n,m[200005],l,ans;
string c,s;
char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> m[i] >> a;
		l += m[i];
		for(int j = 1;j <= m[i];j++)
			s += a;
	}
	for(int i = 0;i < (l + 1) / 2;i++)
	{
		if(s[i] != s[l - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
