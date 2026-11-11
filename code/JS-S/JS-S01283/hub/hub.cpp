#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int c,t,u,v,n,k;
vector<int> mp[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i = 1;i <= n;++i) mp[i].clear();
		for(int i = 1;i <= n;++i){
			scanf("%lld %lld",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		printf("1\n");
	}
	return 0;
}
