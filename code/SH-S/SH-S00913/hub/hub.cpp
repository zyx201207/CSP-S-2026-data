#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int> to[100086];
int ok(int x){
	int num=0;
	bool vis[100086]={0};
	for(int i=1,cnt=0;i<=n;i++){
		if(x&(1<<(i-1))){num++;}
		if((x&(1<<(i-1)))&&!vis[i]){
			cnt++,vis[i]=1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int i=0;i<to[u].size();i++){
					if((x&(1<<(to[u][i]-1)))&&!vis[to[u][i]]){q.push(to[u][i]);vis[to[u][i]]=1;}
				}
			}
		}
		if(cnt>2){return 0;}
	}
	return num==k;
}
int bfs(int msk){
	int res;
	bool vis[100086]={0};
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++){if(msk&(1<<(i-1))){q.push(make_pair(i,0));vis[i]=1;}}
	while(!q.empty()){
		res=q.front().second;
		int u=q.front().first;q.pop();
		for(int i=0;i<to[u].size();i++){
			if(!vis[to[u][i]]){q.push(make_pair(to[u][i],res+1));vis[to[u][i]]=1;}
		}
	}
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int ans=2e9;
		for(int msk=0;msk<(1<<n);msk++){if(ok(msk)&&ans>bfs(msk)){ans=bfs(msk);}}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){to[i].clear();}
	}
	return 0;
}
