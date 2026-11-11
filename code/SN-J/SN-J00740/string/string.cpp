#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], sum, ans;
char c[200005];
int main()
{
	//bian bo yang 西安市第一中学 SN-J00740
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	long long left = 1, right = n;
	while(left < right)
	{
		if (c[left] == c[right])
		{
			if (a[left] > a[right])
			{
				a[left] -= a[right];
				a[right] = 0;
				right--;
			}
			else if (a[left] < a[right])
			{
				a[right] -= a[left];
				a[left] = 0;
				left++;
			}
			else
			{
				a[left] = 0;
				a[right] = 0;
				left++;
				right--;
			}
				
		}
		else
		{
			if (a[left] > a[right])
			{
				a[left] -= a[right];
				ans += a[right];
				a[right] = 0;
				right--;
			}
			else if (a[left] < a[right])
			{
				a[right] -= a[left];
				ans += a[left];
				a[left] = 0;
				left++;
			}
			else
			{
				ans += a[left];
				a[right] = 0;
				a[left] = 0;
				left++;
				right--;
			}
		}
	}
	cout << ans;
	return 0;
}
