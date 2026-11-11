#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,but=1,a[500100],ret[500100],q[500100],l=1,r=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ret[i]=ret[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		q[++r]=a[i];
		while(l<=r&&(r-l+1)*q[r]-ret[r]+ret[l-1]>m)
		{
			l++;
		}
		but=max(but,r-l+1);
	}
	cout<<but;
	return 0;
}
