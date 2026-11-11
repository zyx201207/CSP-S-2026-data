#include<bits/stdc++.h>
using namespace std;
#define N 222222
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int c,t,n,k,u,v,res,ans,dis[N];
vector<int>e[N];
bool vis[N];
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	int ans=1e9;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int res=0;
			queue<int>q;
			q.push(i),q.push(j);
			dis[i]=dis[j]=0;
			memset(vis,0,sizeof(vis));
			while(q.size()){
				int l=q.front();q.pop();
				res=max(res,dis[l]);
				for(auto i:e[l])
					if(!vis[i])dis[i]=dis[l]+1,q.push(l);
			}
			ans=min(ans,res);
		}
	cout<<ans<<endl;
}
int main(){
	open("hub");
	cin>>c>>t;
	while(t--)work();
}