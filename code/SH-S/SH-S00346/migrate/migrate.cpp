#include<bits/stdc++.h>
#define N 2000003
using namespace std;
typedef long long ll;
int c,T;
ll n,d,x[N];
map<ll,ll> mp;
ll Abs(ll t){
	if(t<0)return -t;
	return t;
}
void input(){
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&x[i]);
}
void solveA(){
	ll C=x[2]-x[1];
	if(d<2*C)printf("0\n");
	else printf("%lld\n",(n-1)*(n-2)/2);
}
void solveB(){
	printf("0\n");
}
void solveC(){
	printf("0\n");
}
void solve(){
	for(ll i=1;i<=n;i++)
		mp[x[i]]++;
	ll cnt=0;
	for(ll i=1;i<=n;i++)
		if(mp[x[i]+d]&&mp[x[i]+d*2])
			cnt++;
	printf("%lld\n",cnt);
}
int main(){// (31)8=(25)10
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		input();
		if(c==11||c==12)solveA();
//		else if(c==13||c==14)solveB();
//		else if(c==15||c==16)solveC();
		else solve();
	}
	return 0;
}
