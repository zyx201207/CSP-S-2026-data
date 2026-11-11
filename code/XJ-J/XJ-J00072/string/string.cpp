#include <bits/stdc++.h>
using namespace std;
char b[200005];
int a[200005],n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
		b[i] = int(b[i]-'0');
	}
	int ans = 0;
	for (int i=1;i<=n-1;i++)
	{
		if (b[i] == b[i+1])
		    ans++;
	}
	if (ans==n-1) cout << 0;
	else cout << 1;
	
	return 0;
}
