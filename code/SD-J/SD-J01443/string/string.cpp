# include<bits/stdc++.h>
# define int long long
using namespace std;
const int MX = 2e5;
int a[MX + 10];
char c[MX + 10];
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int ans = 0;
	int l = 1,r = n;
	while(l < r)
	{
		ans+=(c[l] != c[r]) * min(a[l],a[r]);
		bool f = a[l] < a[r];
		int t = min(a[l],a[r]);
		a[l] -= t;
		a[r] -= t;
		l+=f;
		r-=!f;
	}
	cout << ans << endl;
	return 0;
}
