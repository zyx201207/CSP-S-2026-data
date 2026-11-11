#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
struct E {
	int to,nxt;
} e[2000010];
int ne=0;
int hd[1000005];
void adde(int u,int v){
	e[++ne]=(E){v,hd[u]};
	hd[u]=ne;
}
//int built=0;
int req[1000005]; // min
bool dfs(int u){
	;
}
bool OK(int x){
	for(int i=1;i<=n;i++) req[i]=1e16;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ne=0;
		for(int i=1;i<=n;i++) hd[i]=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adde(u,v);
			adde(v,u);
		}
		int l=0,r=n;
		int ans=n;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(OK(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


