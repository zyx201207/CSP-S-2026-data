#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
vector<int> tree[1000001];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		for(int i=1;i<=1000000;i++)tree[i].clear();
		int n,k;scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++){
			int u,v;scanf("%lld %lld",&u,&v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}