#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,t,c,vis[N],ans;
vector<int>a[N];
struct node{
	int x,s,k;
};
queue<node>q;
int f(int x){
	for(int i=1;i<=ans;i++){
		int sum=0;
		memset(vis,0,sizeof vis);
		q.push({x,0,1});
		while(q.size()){
			node nx=q.front();
			q.pop();
			vis[nx.x]=1;
			if(nx.k>m){
				continue;
			}
			if(nx.s>i){
				nx.s=0;
				nx.k++;
			}
			for(int j=0;j<a[nx.x].size();j++){
				if(vis[a[nx.x][j]])continue;
				sum++;
				q.push({a[nx.x][j],nx.s+1,nx.k});
			}
		}
		if(sum>=n){
			return i;
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans=n;
		for(int i=1;i<=ans;i++){
			ans=f(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}