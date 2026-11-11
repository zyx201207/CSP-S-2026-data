#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int e=1e6+10;

int c,t,n,k,ans=inf;
bool is[e],vis[e],nvis[e],fla[e];
vector<int>mp[e];

void read_file(string topic){
	freopen((topic+".in").c_str(),"r",stdin);
	freopen((topic+".out").c_str(),"w",stdout);
	return ;
}

void dfs2(int pos,int cnt){
	if(vis[pos]==1||is[pos]==0)
		return ;
	vis[pos]=1;
	fla[pos]=cnt-1;
	for(int v:mp[pos])
		dfs2(v,cnt);
	return ;
}

bool check(){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	memset(nvis,0,sizeof(nvis));
	for(int i=1;i<=n;i++)
		if(is[i]==1&&vis[i]==0){
			cnt++;
			if(cnt>2)
				return 0;
			dfs2(i,cnt);
		}
	return 1;
}

int bfs(){
	queue<pii>q;
	int res1=inf,res2=inf;
	memset(nvis,0,sizeof(nvis));
	
	for(int i=1;i<=n;i++)
		if(is[i]==1&&fla[i]==1){
			q.push({i,0});
			nvis[i]=1;
		}
		
	while(!q.empty()){
		pii var=q.front();
		q.pop();
		int u=var.first,w=var.second;
		res1=w;
		
		for(int v:mp[u]){
			if(nvis[v])
				continue;
			nvis[v]=1;
			if(is[v]==1&&nvis[v]==0)
				res2=w/2;
			q.push({v,w+1});
		}
	}
	return min(res1,res2);
}

void dfs1(int pos,int cnt){
	if(pos>n){
		if(cnt!=k)
			return ;
		if(check()){
			int var=bfs();
			ans=min(ans,var);
		}
		return ;
	}
	is[pos]=1;
	dfs1(pos+1,cnt+1);
	is[pos]=0;
	dfs1(pos+1,cnt);
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	read_file("hub");

	cin>>c>>t;
	while(t--){
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs1(1,0);
		cout<<ans<<'\n';
		
		for(int i=1;i<=n;i++)
			mp[i].clear();
	}

	return 0;
}
