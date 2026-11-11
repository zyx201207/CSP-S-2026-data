#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,n,d;
int ans=0,ququ=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t>0)
	{
		ll x[200010];
		t--;
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x[i]);
			if(x[i]-x[i-1]>d)
			{
				scanf("%lld",&x[20009]);
			}
		} 
		if(c==11 || c==12)
		{
			ll ppp=x[1]-x[0];
			if(ppp<d)
			{
				ll washen=0;
				for(int i=0;i<n;i++)
				{
					washen+=ppp;
					if(washen>=d+ppp && i>2)
					{
						if(washen==d+ppp)
						{
							printf("%lld\n",n-i-1);
						}
						else
						{
							printf("%lld\n",n-i);
						}
						break;
					}
				}
				
			}
			else if(ppp>=d)
			{
				printf("0\n");
			}
		}
	}
	return 0; 
} 
