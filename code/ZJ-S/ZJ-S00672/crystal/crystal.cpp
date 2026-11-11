#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[500010],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long c=0;
	int l=1,num=1;
	for (int i=2;i<=n;i++)
	{
		c+=num*(a[i]-a[i-1]);
		num++;
		while (c>m)
		{
			num--;
			c-=a[i]-a[l];
			l++;
		}
		ans=max(ans,num);
	}
	cout << ans;
	return 0;
}