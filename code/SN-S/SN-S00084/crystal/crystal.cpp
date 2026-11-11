#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[200005],m,ans=0;
ll llmax(ll a,ll b){
	return a>b?a:b;
}
ll check(ll x){
	ll tot=0,cnt=0;
	int e=upper_bound(a+1,a+n+1,x)-a;
	e--;
	for(int i=e;i>=1;i--){
		if(a[i]>x){
			continue;
		}
		else{
			int k=x-a[i];
			if(cnt+k>m){
				return tot;
			}
			cnt+=k;
			tot++;
		}
	}
	return tot;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=a[1];i<=a[n];i++){
		ans=llmax(ans,check(i));
	}
	if(n>500000){
		ans=check(a[n]);
	}
	printf("%lld",ans);
	return 0;
} 
