#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char c[200005];
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int j=n;
	long long ans=0;
	for (int i=1; i<=j; i++)
	{
		i--;
		if (a[i]>a[j])
		{
			a[i]-=a[j];
			if (c[i]!=c[j])
			{
				ans+=a[j];
			}
			j--;
		}
		else if(a[i]==a[j])
		{
			if (c[i]!=c[j])
			{
				ans+=a[i];
			}
			i++;
			j--;
		}
		else
		{
			a[j]-=a[i];
			if (c[i]!=c[j])
			{
				ans+=a[i];
			}
			i++;
		}
	}
	cout << ans;
	return 0;
}
