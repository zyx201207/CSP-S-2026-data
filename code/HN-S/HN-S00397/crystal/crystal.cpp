#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],m,n,x,k,ans=1,sum=1,d;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	x=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[1];
	for(int i=2;i<=n;i++)
	{
		k=i;ans=1;
		while(x-ans*(b[k]-b[k-1])>=0)
		{
			x-=ans*(b[k]-b[k-1]);
			ans++;
			k++;
			if(k>n)break;
		}
		if(ans>sum)sum=ans;
		x=m;
	}
	printf("%lld",sum);
	return 0;
}
