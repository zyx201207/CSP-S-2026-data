#include<bits/stdc++.h>
const int N=2000010;
std::vector<int>g[N];
int n,k;
int p[30];
bool flag[N],tt[N],vis[N],d[N];
void bfs(int x){
	std::queue<int>q;
	q.push(x);
	flag[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(flag[v]){
				continue;
			}
			flag[v]=1;
			q.push(v);
		}
	}
}
int bbfs(int x){
	std::queue<int>q;
	q.push(x);
	vis[x]=1;
	d[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(tt[u]){
			return d[u];
		}
		for(int v:g[u]){
			if(vis[v]){
				continue;
			}
			d[v]=d[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
}
int ans=1000000000;
void dfs(int r,int last){
	if(r==k){
		std::string s="                                                                                                          ";
		for(int i=1;i<=n;i++){
			s[i]='6';
			flag[i]=0;
			vis[i]=0;
			tt[p[i-1]]=1;
			d[i]=0;
		}
		for(int i=1;i<=r;i++){
			s[p[i-1]]='7';
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='7'&&!flag[i]){
				bfs(i);
				cnt++;
			}
			if(cnt>=3){
				break;
			}
		}
		if(cnt<=2){
			int tmp=0;
			for(int i=1;i<=n;i++){
				tmp=std::max(bbfs(i),tmp);
			}
			ans=std::min(ans,tmp);
		}
		return;
	}
	for(int i=last;i<n;i++){
		p[i]=i+1;
		dfs(r+1,i+1);
		p[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	int c,t;
	std::cin>>c>>t;
	while(t--){
		std::cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			std::cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		std::cout<<ans<<'\n';
		ans=1000000000;
	}
	return 0;
}

