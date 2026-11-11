#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001];
long long cnt,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		cnt+=a[i];
	}
	int l = 1,r = n;
	while (l < r)
	{
		if (c[l] != c[r])
		{
			ans+=min(a[l],a[r]);
		}
		if (a[l] < a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else if (a[l] > a[r])
		{
			a[l]-=a[r];
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}