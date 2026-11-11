#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],sum[N],ans=1;
ll f1=1,f2=1,l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fori(1,n,1){
		scanf("%lld",&a[i]);
		if(a[i]!=i)f1=0;
	}
	sort(a+1,a+n+1);
	fori(1,n,1){
		sum[i]=a[i]-a[i-1];
		if(sum[i]!=sum[i-1]&&i!=1&&i!=2)f2=0;
	}
	if(sum[1]<0)a[0]=2*sum[1];
	if(f1){
		ll p=sqrt(2*m);
		for(ll i=p;;i++){
			if(i*(i-1)/2>m){printf("%lld",i-1);return 0;}
		}
	}
	if(f2){
		ll mi=a[2]-a[1];
		ll p=sqrt(2*m);
		for(ll i=p;;i++){
			if(i*(i-1)/2*mi>m){printf("%lld",i-1);return 0;}
		}
	}l=1;ll cnt=0;
	fori(2,n,1){
		cnt=cnt+(i-l)*(a[i]-a[i-1]);
		if(cnt<=m)ans=max(ans,i-l+1);
		while(cnt>m){
			cnt=cnt-(a[i]-a[l]);l++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
