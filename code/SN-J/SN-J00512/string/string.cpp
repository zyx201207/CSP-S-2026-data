#include <bits/stdc++.h>
using namespace std;

int n,l,r;
long long a[200005],minn,ans;
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i] >> c[i];
	l = 1,r = n;
	while(l < r)
	{
		minn = min(a[l],a[r]);
		a[l] -= minn;
		a[r] -= minn;
		if(c[l] != c[r])ans += minn;
		if(a[l] == 0)l++;
		if(a[r] == 0)r--;
	}
	cout << ans << endl;
	return 0;
}
