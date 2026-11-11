#include <iostream>
using namespace std;
long long a[200005],n,ans,l,r;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	l=1,r=n;
	while (l<r)
	{
		if (c[l] != c[r])
		{
			if (a[l] > a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if (a[l] < a[r])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else
			{
				ans+=a[l];
				l++;
				r--;
			}
		}

		else
		{
			if (a[l] > a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if (a[l] < a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
