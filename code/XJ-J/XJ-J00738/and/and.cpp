#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[200005],ans;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i;
	cin >> n >> m;
	for (i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for (i=2; i<=m; i++)
		ans&=a[i];
	cout << ans;
	return 0;
}
