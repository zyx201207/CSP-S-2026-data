#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt,ans=10005;
bool vis[1005];
vector<int>e[1005],S[10005],now;
void bfs(int st){
	queue<int>q;
	q.push(st);
	vis[st]=true;
	bool in[1005];
	memset(in,false,sizeof(in)); 
	for(int i=0;i<now.size();i++){
		in[now[i]]=true;
	}
	while(!q.empty()){
		int fr=q.front();
		q.pop();
		for(int i=0;i<e[fr].size();i++){
			int to=e[fr][i];
			if(in[to]&&!vis[to]){
				q.push(to);
			}
			vis[to]=true;
		} 
	}	
}
int bfs2(int st,vector<int>s){
	memset(vis,false,sizeof(vis)); 
	queue<pair<int,int> >q;
	q.push({st,0});
	bool in[10005];
	for(int i=0;i<s.size();i++){
		in[s[i]]=true;
	} 
	while(!q.empty()){
		pair<int,int>fr=q.front();
		q.pop();
		if(in[fr.first]){
			return fr.second;
		}
		for(int i=0;i<e[fr.first].size();i++){
			int to=e[fr.first][i];
			if(!vis[to]){
				vis[to]=true;
				q.push({to,fr.second+1});
			}
		}
	}
}
bool check(vector<int>now){
	memset(vis,false,sizeof(vis));
	int tot=0;
	for(int i=0;i<now.size();i++){
		if(!vis[i]){
			tot++;
			bfs(i);
		}
	}
	return tot<=2;
}
void dfs(int dep,int pos){
	if(dep==k){
		if(check(now)){
			S[++cnt]=now;	
		}
//		for(int i=0;i<now.size();i++){
//			cout<<now[i]<<" ";
//		}
//		cout<<"\n";
		return;
	}
	if(pos==n){
		return;
	}
	dfs(dep,pos+1);
	now.push_back(pos);
	dfs(dep+1,pos+1); 
	now.pop_back();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=10005,cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(0,1);
//		for(int i=1;i<=cnt;i++){
//			for(int j=0;j<S[i].size();j++){
//				cout<<S[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		for(int i=1;i<=cnt;i++){
			int maxn=-1;
			for(int j=1;j<=n;j++){
				maxn=max(maxn,bfs2(j,S[i]));
			}
			if(maxn==1){
				for(int j=0;j<S[i].size();j++){
					cout<<S[i][j]<<" ";
				}
				return 0;
			}
			ans=min(ans,maxn);
		}
		cout<<ans<<"\n";
//		for(int i=1;i<=cnt;i++){
//			S[i].clear();
//		}
//		for(int i=1;i<=n;i++){
//			e[i].clear();
//		}
	}
	return 0;
} 
