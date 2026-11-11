#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
using namespace std;
const int N=5e5+10,M=510;
int c,n,m,d,Q,flag=1;
int k[M],w[N];
vector<ll> a[M],t[M],id[N];
vector<PLL> g[M*2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		g[0].push_back({i,w[i]});
		g[i].push_back({0,w[i]});
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if(k[i]>2) flag=0;
		for(int j=1;j<=k[i];j++){
			ll x,y;
			scanf("%lld %lld",&x,&y);
			a[i].push_back(x);
			id[x].push_back(i);
			t[i].push_back(y);
			g[m+x].push_back({0,y});
			g[0].push_back({m+x,y});
		}
		for(int j=0;j<k[i]-1;j++) g[m+a[i][j]].push_back({m+a[i][j+1],0});
	}
	if(n==2){
		while(Q--){
			int l,r;
			ll ans=inf;
			scanf("%d %d",&l,&r);
			for(int p:id[l]){
				
			}
		}
		return 0;
	}
	while(Q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(flag){
			
		}
	}
	
	
	return 0;
}
