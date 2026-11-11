#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c,tx,x[N],mn[N],t[N],ans,n,d;
void dfs(int id,int c){
	if(mn[id] > c){
		mn[id] = c;
		t[id] = 1;
	}else if(mn[id] == c){
		t[id] += 1;
	}
	for(int i = id + 1;i <= n;++i){
		if(i > n) return;
		if(x[i] - x[id] <= d){
			dfs(i,c + 1);
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&tx);
	while(tx--){
		ans = 0;
		scanf("%lld %lld",&n,&d);
		if(n <= 5000){
			for(int i = 1;i <= n;++i){
				scanf("%lld",&x[i]);
			}
			for(int i = 1;i <= n;++i){
				memset(mn,0x3f,sizeof(mn));
				memset(t,0,sizeof(t));
				dfs(i,0);
				for(int i = 1;i <= n;++i){
					if(t[i] == 2) ans += 1;
				}
			}
			printf("%lld\n",ans);
		}else{
			printf("%lld\n",n * (n - 1) / 2);
		}
	}
	return 0;
}
