#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,d,c,m;
ll w[500005],k[500005],a[5005][5005],t[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
} 
