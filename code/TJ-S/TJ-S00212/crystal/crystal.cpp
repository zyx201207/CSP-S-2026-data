#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005]={},sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int zhong=a[(n+1)/2];
	for(int i=1;i<=n;i++) a[i]=abs(zhong-a[i]);
	sort(a+1,a+n+1);
 	for(int i=1;i<=n;i++)
	{
		if (sum==m)
		{
			cout<<i-1;
			return 0;
		}
		if (sum>m)
		{
			cout<<i-2;
			return 0;
		}
		sum+=a[i];
	}
	return 0;
}
