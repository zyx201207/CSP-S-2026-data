#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
long long dp[2000005],ans;
void solve(){
	int n;
	long long d;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	if(11<=c&&c<=12){
		long long t=a[2]-a[1];
		if(d<2*t){
			printf("0\n",n-2);
		}else{
			printf("%d\n",max(n-(d/t*2-1),0ll));
		}
		return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		solve();
	}
	return 0;
}
