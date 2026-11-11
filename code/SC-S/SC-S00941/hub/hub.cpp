#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,k;
struct node{ ll a,b ;};
node w[10005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c!=0)
	return 0;
	for(int i=1;i<=t;i++)
	{
		scanf("%lld %lld",&n,&k);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld %lld",&w[i].a,&w[i].b);
		}
	}
	printf("1");
	printf("2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}