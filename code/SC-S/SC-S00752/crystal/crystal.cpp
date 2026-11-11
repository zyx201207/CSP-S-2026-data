#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++) cha[i]=a[i+1]-a[i];
	int l=1,r=0;
	long long need_=0,last=0;
	int maxn=1;
	while(1)
	{
		if(r+1<=n-1) r++;
		else break;
		//cout<<l<<" "<<r<<"\n";
		need_+=(r-l+1)*cha[r];
		last+=cha[r];
		while(need_>m)
		{
			need_-=last;
			last-=cha[l];
			l++;
			//cout<<l<<" "<<r<<"\n";
		}
		maxn=max(maxn,r-l+1);
	}
	printf("%d",maxn+1);
	return 0;
} 