#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6;
int c,t,n;
ll d;
ll x[M]; 
ll ans;
void sol(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	if(d<x[2]-x[1]){
		printf("0\n");
		return;
	}
	for(int i=3;i<=n;i++){
		if(i%(d/(x[2]-x[1]))==1){
			ans=ans+n-i+1;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		sol();
	}
	return 0;
}