#define ll long long

#include<bits/stdc++.h>
using namespace std;
const int mx = 2e6 + 10;
ll x[mx];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	int n;
	ll d;
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++)scanf("%lld",&x[i]);
		ll g = x[2] - x[1];
		if(g * 2 <= d && g * 3 > d)printf("%d\n",n - 3);
		else printf("0\n");
	}
	return 0;
}
