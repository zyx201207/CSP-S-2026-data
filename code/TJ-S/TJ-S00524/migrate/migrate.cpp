#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,x[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}cout<<n*(n-1)/2<<'\n';
	}
	return 0;
} 
