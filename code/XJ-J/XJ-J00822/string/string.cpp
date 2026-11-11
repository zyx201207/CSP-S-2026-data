#include <bits/stdc++.h>
using namespace std;
long long s,at[999999], ans;
char cnt[999999];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> s;
	
	for (int i = 1; i <= s; i++)
	{
		cin >> at[i] >> cnt[i];
	}
	for (int j = 1; j <= s / 2; j++) if (cnt[j] >= at[s - j - 1]) if (at[j] >= at[s - j - 1])ans += at[j];
	else ans += at[s - j - 1];
	cout << ans << endl;
	return 0;
}