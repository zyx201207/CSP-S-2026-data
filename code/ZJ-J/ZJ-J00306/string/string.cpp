#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
pair<int, char> a[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d %c", &a[i].first, &a[i].second);
	for(int i = 1, j = n; i < j; )
	{
		int x = min(a[i].first, a[j].first);
		if(a[i].second != a[j].second) ans += x;
		if(a[i].first < a[j].first) a[j].first -= x, i++;
		else if(a[i].first > a[j].first) a[i].first -= x, j--;
		else i++, j--;
	}
	cout << ans;
	return 0;
}
