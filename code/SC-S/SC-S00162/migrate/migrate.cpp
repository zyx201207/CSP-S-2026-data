#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
typedef long long ll;

void solve(){
	ll n,d;
	vector<ll> x={0};
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		ll xx;
		scanf("%lld",&xx);
		x.push_back(xx);
	}
	ll dis=x[2]-x[1];
	ll gap=d/dis;
	if(gap<=1) printf("%d\n",0);
	else{
		printf("%lld\n",n-1-gap);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	fclose(stdin),fclose(stdout);
	return 0;
}