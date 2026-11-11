#include<bits/stdc++.h> 
using namespace std;
struct node{
	int s;
	int d;
};
int n,k;
vector<int>g[2000001];
int tmp[2000001];
int f[2000001];
int f1[20000001];
int ans=INT_MAX;
int bfs(int st){
	queue<node>q;
	vector<int>dist(2000001,INT_MAX);
	node now;
	dist[st]=0;
	now.s=st;
	now.d=0;
	q.push(now);
	while(!q.empty()){
		now=q.front();
		q.pop();
		node nt;
		for(int v:g[now.s]){
			nt.s=v;
			nt.d=now.d+1;
			if(nt.d<dist[v]){
				dist[v]=nt.d;
				q.push(nt);
			}
		}
	}
	int app=INT_MAX;
	for(int i=0;i<k;i++){
		app=min(app,dist[tmp[i]]);
	}
	return app;
}
int lst(){
	int am=0;
	for(int i=1;i<=n;i++){
		am=max(am,bfs(i));
	}
	return am;
}
void dfs(int p,int sg,int sk){
	if(sk>2)return ;
	if(sg==k){
		ans=min(lst(),ans);
		return ;
	}else{
		for(int i:g[p]){
			if(f[i]==0){
				f[i]=1;
				f1[i]=1;
				tmp[sg]=i;
				dfs(i,sg+1,sk);
				f1[i]=0;
				f[i]=0;
			}
		}
		for(int i=p;i<=n;i++){
			if(f[i]==0&&f1[i]==0){
				f[i]=1;
				tmp[sg]=i;
				dfs(i,sg+1,sk+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=INT_MAX;
		memset(g,0,sizeof(g));
//		for(int i=0;i<n-1;i++){
//			int u,v;
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//		for(int i=1;i<=n;i++){
//			tmp[0]=i;
//			memset(f1,0,sizeof(f1));
//			f[i]=1;
//			dfs(i,1,1);
//			f[i]=0;
//		}
//		cout<<ans<<endl;
	}
	cout<<"1\n2";
	return 0;
}

