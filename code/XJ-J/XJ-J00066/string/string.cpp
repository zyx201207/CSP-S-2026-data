#include <bits/stdc++.h>
using namespace std;
const int MAXN = 999999000;
char ch[MAXN],c;
long long n,b,ci = 1,mid,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> b >> c;
		for(int j = 1;j<=b;j++)
		{
			ch[ci] = c;
			ci++;
		}
	}
	mid = ceil(1.0 * ci/2);
	for(int i = 1;i<=mid;i++)
	{
		if(!(ch[i] == ch[ci-i]))
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
