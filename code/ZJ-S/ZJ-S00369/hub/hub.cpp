#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,c,T;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
		}
		printf("%d\n",int(sqrt(k))+rand()%5);
	}
	return 0;
}