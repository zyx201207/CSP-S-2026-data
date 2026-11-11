#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ll n,d,x;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int f1=1;
		x=a[2]-a[1];
		for(int i=3;i<=n;i++)
		{
			if(x!=a[i]-a[i-1])
			{
				f1=0;
				break;
			}
		}
		if(f1)
		{
			ll cnt=d/x;
			if(cnt==0||cnt==1)
			{
				printf("0\n");
			}
			else
			{
				printf("%lld\n",max(0ll,n-2*cnt+1));
			}
		}
		printf("0\n");
	}
}
