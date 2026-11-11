#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,k,a[N],d[N],b[N],minn=100;
vector<int>g[N];
void cov(int x){
	b[x]=0;
	for(int i:g[x]){
		if(b[i]==1) cov(i);
	}
}
void ca(int x,int fa){
	for(int i:g[x]){
		if(i==fa) continue;
		if(d[i]<=d[x]+1) continue;
		d[i]=d[x]+1;
		ca(i,x);
	}
}
void dfs(int x){
	if(x>n){
		int s=0;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) s++;
			b[i]=a[i];
		}
		if(s!=k) return;
		s=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				cov(i);
				s++;
			}
		}
		if(s>2) return;
		for(int i=1;i<=n;i++) d[i]=n+1;
//		cout<<":";
		for(int i=1;i<=n;i++){
			if(a[i]){
				d[i]=0;
//				cout<<i<<" ";
				ca(i,0);
			}
		}
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,d[i]);
		}
		minn=min(minn,ma);
//		cout<<"\n"<<minn<<" "<<s<<"\n"; 
		return;
	}
	a[x]=1;
	dfs(x+1);
	a[x]=0;
	dfs(x+1);
} 
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	minn=200;
	dfs(1);
	cout<<minn<<"\n";
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

