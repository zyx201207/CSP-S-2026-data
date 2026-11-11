#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10; 
ll n,m,a[N],ans=1,s[N];
ll check(ll i){
	ll x=a[i];
	ll st=lower_bound(a+1,a+n+1,x)-a;
	ll ed=upper_bound(a+1,a+n+1,x)-a-1;
	ll l=1,r=st-1,mid,sum,res,rq;
	while(l<=r){
		mid=(l+r)/2,res=(st-mid)*x;
		sum=s[st-1]-s[mid-1],rq=res-sum;
		if(rq<=m)r=mid-1;
		else l=mid+1;
		//printf("X:%lld sum:%lld mid:%lld rq:%lld\n",x,sum,mid,rq);
	}
	//printf("L:%lld R:%lld ---ANS: %lld\n",l,ed,ed-l+1);
	return ed-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		ans=max(ans,check(i));
	}
	printf("%lld",ans);
	return 0;
}

/*
11 6
1 2 2 2 2 3 3 3 3 3 9
*/
