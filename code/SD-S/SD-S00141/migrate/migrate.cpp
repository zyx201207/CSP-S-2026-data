#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll n,d,a[N],dp[N];
void solve(){
	scanf("%lld %lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	if(a[n]-a[1]==n-1){	
		int len=d*2-1;
		if(n<len) puts("0");
		else printf("%lld\n",n-len);
	}
	else puts("0");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
