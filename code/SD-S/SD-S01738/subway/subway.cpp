#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	ll minn=1e9+10;
	for(int i=1;i<=m;i++) minn=min(minn,w[i]);
	while(q--) cout<<minn<<"\n";
	return 0;
}

