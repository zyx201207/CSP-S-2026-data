#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],n,k,l,h,b,ans;
void solveA(){
	if(m==0){
		cout<<1;
		return;
	}
	long long m1=1;
	ans=2;
	while(m1<=m){
		if(ans==n){
			cout<<ans;
			return;
		}
		m1+=ans;
		ans++;
	}
	cout<<ans-1;
}
void solveB(){
	if(m<l){
		cout<<1;
		return;
	}
	long long m1=l;
	ans=2;
	while(m1<=m){
		if(ans==n){
			cout<<ans;
			return;
		}
		m1=m1+ans*l;
		ans++;
	}
	cout<<ans-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==i)k++;
	}
	l=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]==l)h++;
	}
	if(k==n){
		solveA();
		return 0;
	}
	if(h==n-2){
		solveB();
		return 0;
	}
	solveB();
	return 0;
} 