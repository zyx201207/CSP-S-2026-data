#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],cnt;
char a1[200005];
string s;

int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n; i++) cin >> a[i] >> a1[i];
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= a[i]; j++) s += a1[i];
	int m = s.size();
	for (int i = 0;i < m / 2; i++)
		if (s[i] != s[s.size() - i]) cnt++;
	cout << cnt;
	return 0;
} 
