#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans;
struct node
{
	char ch;
	long long num;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].ch;
	}
	long long l=1,r=n;
	while (l<=r)
	{
		long long drt=min(a[l].num,a[r].num);
		if (a[l].ch==a[r].ch)
		{
			if (a[l].num>a[r].num)
			{
				a[l].num-=drt;
				r--;
			}
			else if (a[l].num==a[r].num)
			{
				l++;
				r--;
			}
			else
			{
				l++;
				a[r].num-=drt;
			}
		}
		else
		{
			if (a[l].num>a[r].num)
			{
				ans+=drt;
				a[l].num-=drt;
				r--;
			}
			else if (a[l].num==a[r].num)
			{
				ans+=drt;
				l++;
				r--;
			}
			else
			{
				ans+=drt;
				l++;
				a[r].num-=drt;
			}
		}
	}
	cout<<ans;
	return 0;
}
