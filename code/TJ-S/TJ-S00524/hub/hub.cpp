#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
vector<int>G[1000006];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld %lld",&u,&v);
		}n-=2*k;
		int m=(n+1)/2;
		cout<<(m)/4+1<<'\n';
	}
	return 0;
}
