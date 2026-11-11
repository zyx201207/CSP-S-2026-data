#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int t,n,k,v1[100001],v2[100001],c,mi=1999999999,ma,d[100001];
vector<int> g[100001];
void dfs(int x){
	v2[x]=1;
	for(auto v:g[x]){
		if(v1[v]==1&&v2[v]==0){
			dfs(v);
		}
	} 
}
void bfs(){
	queue<int> q;
	memset(v2,0,sizeof(v2));
	for(int i=1;i<=n;i++){
		if(v1[i]==1){
			q.push(i);
			d[i]=0;
			v2[i]=1;
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(v2[v]==0){
				v2[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);
	cin>>t;
	cin>>t;
	while(t--){
		mi=1999999999;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=0;i<(1<<n);i++){
			memset(v1,0,sizeof(v1));
			memset(v2,0,sizeof(v2));
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					v1[j+1]=1;
					c++;
				}
			}
			if(c!=k){
				continue;
			}
			c=0;
			for(int j=1;j<=n;j++){
				if(v1[j]==1&&v2[j]==0){
					c++;
					dfs(j);
				}
			}
			if(c>2){
				continue;
			}
			ma=0;
			bfs();
			for(int i=1;i<=n;i++){
				ma=max(ma,d[i]);
			}
			mi=min(mi,ma);
		}
		cout<<mi<<'\n';
	}
	return 0;
} 
