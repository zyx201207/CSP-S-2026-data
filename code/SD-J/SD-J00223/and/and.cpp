#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[200100];
ll a[200010]; 
ll n,m,pnt;
bool numx[33],numy[33];
bool ans[33];
bool cmp(ll x,ll y){
	return x>y;
}
ll f(ll x,ll y){
	ll p=1,q=1;
	while(x!=1){
		if(x%2==0) numx[p]=1;
		p++;
		x/=2;
	}
	while(y!=1){
		if(y%2==0) numy[q]=1;
		q++;
		y/=2;
	}
	for(int i=1;i<=min(p,q);i++){
		if(numx[i]==numy[i]&&numx!=false){
			ans[i]=1;
		}
	}
	ll op=1;
	for(int i=1;i<=min(p,q);i++){
		if(ans[i]==1) pnt+=ans[i]*op;
		op*=2;
	}
	return pnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[j]=max(dp[j-1],f(dp[i-1],a[j]));
		}
	}
	cout<<dp[n];
	return 0;
} 
