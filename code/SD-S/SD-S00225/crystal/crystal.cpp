#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5+10;
long long n,m,t,ans,tot;
bool flag=0;
long long a[maxN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
	{
		tot+=(a[n]-a[i]);
	}
	if(tot<=m)
	{
		cout<<n;
		return 0;
	}
	for(int j=n;j>=1;j--)
	{
		ans=j;
		if(tot<=m)
		{
			t=max(t,ans);
			continue;
		}
		else
		{
			int i=1,temp=tot;
			while(temp>m && ans>t)
			{
				temp-=a[j]-a[i];
				ans--,i++;
			}
		}
		tot-=(a[j]-a[j-1])*(j-1);
		t=max(t,ans);
	}
	cout<<t;
	return 0;
}
