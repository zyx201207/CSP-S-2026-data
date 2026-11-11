#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int l = 1,r = 1,li = 1,ri = n;
	while(li < ri)
	{
		int plus = min(a[li] - l,a[ri] - r) + 1;
		if(c[li] != c[ri]) ans += plus;
		l += plus,r += plus;
		if(l > a[li]) l = 1,li++;
		if(r > a[ri]) r = 1,ri--;
	}
	cout << ans;
	return 0;
}
