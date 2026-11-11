#include <bits/stdc++.h>
using namespace std;
long long m,n,a[500005],s[500005];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (long long i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		long long l=0,r=i;
		while (l!=r)//二分向前查找 
		{
			long long mid=(l+r)/2;
			if (  a[i]*(i-mid+1)-s[i]+s[mid-1] <=m) r=mid; //比较成本 
			else l=mid+1;
			//cout << mid << endl;
		}
		ans=max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}

 
