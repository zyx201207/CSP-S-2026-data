#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
using namespace std;
const ll N=2e5+5;
ll n,m,a[N],ans=-1;
bool cmp(const ll &a,const ll &b){
	return a>b;
}
ll dfs(ll x,ll num,ll step){
	if(step==m){
		if(num>ans)ans=num;
		return 0;
	}
	if(m-step>n-x)return 0;
	fori(x+1,n,1){
		dfs(i,(num&a[i]),step+1);
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fori(1,n,1){scanf("%lld",&a[i]);}
	sort(a+1,a+n+1,cmp);
	if(m==1){printf("%lld",a[1]);return 0;}
	if(m==n){
		ll cnt=a[1];
		fori(2,n,1)cnt=(cnt&a[i]);
		printf("%lld",cnt);
		return 0;
	}
	fori(1,n-m,1){dfs(i,a[i],1);}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
