#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],x,a[500010],t[500010];
int dis[500010],vis[500010];
struct node{
	int v,w;
	bool operator<(const node&b)const{
		return w>b.w;
	}
};
vector<node>ve[500010];
void dijkstra(int s){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;i++)dis[i]=2147483647;
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int k=t.v;
		if(vis[k])continue;
		vis[k]=1;
		for(auto it:ve[k]){
			int v=it.v,w=it.w;
			if(dis[k]+w<dis[v]){
				dis[v]=dis[k]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>t[a[j]];
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				ve[a[j]].push_back({a[k],t[a[j]]+t[a[k]]});
				ve[a[k]].push_back({a[j],t[a[j]]+t[a[k]]});
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dijkstra(l);
		cout<<w[l]+dis[r]+w[r]<<"\n";
	}
	return 0;
}
