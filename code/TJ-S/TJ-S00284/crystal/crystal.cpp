#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ch[500005],ans=1;
bool f1=1,f2=1;
ll solve1(){
	ll k=0;
	for(ll i=1;;i++){
		k+=i;
		if(k>m) return i;
		if(i>=n-1) return n;
	}
}
ll solve2(ll d){
	ll k=0;
	for(ll i=1;;i++){
		k+=i*d;
		if(k>m) return i;
		if(i>=n-1) return n;
	}
}
bool check(ll x){
	for(int i=1;i<=n-x+1;i++){
		if(ch[i]-ch[i+x]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll d;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) f1=0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ch[i]=abs(a[i]-a[i-1]);
	}
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d) f2=0;
		d=a[i]-a[i-1];
	}
	if(f1){
		cout<<solve1();
		return 0;
	}
	if(f2){
		cout<<solve2(d);
		return 0;
	}
	
	for(int i=n-1;i>=1;i--){
		ch[i]+=ch[i+1];
	}
	ll l=1,r=1e18,mid,x;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			x=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<x<<endl;
	
	fclose(stdin);
	fclose(stdout);
}
