#include<bits/stdc++.h>
using namespace std;
int n;
struct bxsx{
	long long a,b;
}h[1000007];
long long m,a[1000007],cha[1000007];
long long juedui(long long a,long long b){
	long long cc=a-b;
	if(cc>0) return cc;
	else return -cc;
}
int ans=0,maxp,maxd;
void erfen(int x){
	if(x!=n)
		if(x==maxp||x==maxd) return;
	long long rp=0;
	for(int i=1;i<=x;i++){
		rp+=(a[x]-a[i]);
	}
	if(rp<=m){
		ans=max(ans,x);
		if(x==n) return;
		maxp=x;
		erfen((maxp+maxd)/2);
	}
	else{
		maxd=x;
		erfen((maxp+maxd)/2);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	maxp=1;maxd=n;
	erfen(n);
	if(n<=10000){
		int cnt,ppoo=ans;
	for(int i=ans+1;i<=n;i++){
		cnt=1;
		int oo=0;
		for(int j=i-1;j>0;j--){
			oo+=(a[i]-a[j]);
			if(oo<=m) cnt++;
			else break;
		}
		ppoo=max(cnt,ppoo);
	}
	cout<<ppoo;
	}
	else cout<<ans;
	return 0;
}