#include<bits/stdc++.h>
using namespace std;
const int maxn=22;
vector<int> g[maxn];
int fa[maxn],n,k,x[maxn],y[maxn],dis[maxn];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int calc(int s){
	memset(dis,-1,sizeof dis);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++){
		if(((s>>x[i]-1)&1)&&((s>>y[i]-1)&1)){
			int fx=find(x[i]),fy=find(y[i]);
			if(fx!=fy) fa[fx]=fy;
		}		
	}
	queue<int> q;
	int cnt=0;
	for(int i=1;i<=n;i++)
	if((s>>i-1)&1){
		if(find(i)==i) cnt++;
		q.push(i);dis[i]=0;
	}
	if(cnt>2) return 1145;
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:g[u])
		 if(dis[v]==-1){
		 	dis[v]=dis[u]+1;
		 	q.push(v);
		 }
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
	return ans;
}
void solve(){
	cin>>n>>k;int ans=1145;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		cin>>x[i]>>y[i];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	for(int s=1;s<(1<<n);s++) 
	if(__builtin_popcount(s)==k) ans=min(ans,calc(s));
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;cin>>t>>t;
	while(t--) solve();
	return 0;
}