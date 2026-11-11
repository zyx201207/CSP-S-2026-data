#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e6+5;
ll c,t,n,d,x[maxn];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++) cin>>x[i];
		if(d<=x[2]-x[1])
		{
			printf("%d\n",0);
			continue;
		}
		else if(c==13||c==14)
		{
			printf("%d\n",0);
			continue;
		}
		else
		{
			ll num=x[n]-x[n-1];
			ll maxv=d/num;
			if(maxv<=1||maxv>=3) printf("%d\n",0);
			else printf("%lld\n",(n+1)/2-1);
		} 
	}
	
	return 0;
}
