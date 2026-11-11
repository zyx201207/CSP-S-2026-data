#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int num;
	char c;
}a[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].num<a[r].num)
			{
				a[r].num-=a[l].num;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				l++;r--;
			}
			else
			{
				a[l].num-=a[r].num;
				r--;
			}
		}
		else
		{
			if(a[l].num<a[r].num)
			{
				a[r].num-=a[l].num;
				ans+=a[l].num;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				ans+=a[l].num;
				l++;
				r--;
			}
			else
			{
				a[l].num-=a[r].num;
				ans+=a[r].num;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
