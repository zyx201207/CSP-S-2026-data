#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
using namespace std;
const ll N=5e5+5;
const ll M=3e5+5;
ll n,m,num[M],a[N],last[M];
ll f=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fori(1,n,1){
		scanf("%lld",&a[i]);
		last[a[i]]=i;
		if(a[i]<a[i-1])f=0;
	}
	if(f){
		fori(1,m,1)printf("%lld ",last[i]);
		return 0;
	}
	fori(0,n-1,1){
		ll node=i+1;
		while(node<=n){
			if(node=last[a[node]]){num[a[node]]++;node++;}
			else node=last[node];
		}
	}
	fori(1,m,1)printf("%lld ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
