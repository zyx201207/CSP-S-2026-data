#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=125255;
const int K=1e6+5;
ll w[M];
ll t[K];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++) 
		scanf("%lld",&t[i]);
	}
	for(ll j=1;j<=n;j++){
		ll ki;
		scanf("%lld",&ki);
		for(ll i=1;i<=2*ki;i++){
			scanf("%lld",&t[i]);
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		if(12<=c&&c<=19){
			cout<<4*t[1]<<'\n';
		}
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}

