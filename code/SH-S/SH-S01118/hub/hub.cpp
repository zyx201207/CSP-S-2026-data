#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,ans,chose[100001],dis[300001];
bool chos[100001],vis1[300001],vis2[300001];
vector<int> g[300001];
void dfs1(int u){
	vis1[u]=1;
	for(auto v:g[u]){
		if(vis1[v]||!chos[v])continue;
		dfs1(v);
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		vis1[i]=0;
	}
	for(int i=1;i<=k;i++){
		if(!vis1[chose[i]]){
			cnt++;
			dfs1(chose[i]);
		}
	}
	if(cnt>2)return false;
	return true;
}
void dfs(int step){
	if(step==k+1){
		if(!check())return ;
		int res=-1;
		queue<pair<int,int> > que;
		for(int i=1;i<=n;i++){
			if(chos[i])continue;
			for(int j=1;j<=n;j++){
				vis2[j]=0;
			}
			que.push({0,i});
			while(!que.empty()){
				auto u=que.front();
				que.pop();
				//cout<<u.second<<"\n";
				if(vis2[u.second])continue;
				vis2[u.second]=1;
				bool f=0;
				
				for(auto v:g[u.second]){
					if(vis2[v])continue;
					//cout<<u.second<<" "<<v<<"\n";
					if(chos[v]){
						//cout<<u.second<<" "<<v<<"\n";
						res=max(res,u.first+1);
						f=1;
						break;
					}
					que.push({u.first+1,v});
				}
				if(f)break;
			}
			while(!que.empty()){
				que.pop();
			}
		}
		ans=min(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!chos[i]){
			chos[i]=1;
			chose[step]=i;
			dfs(step+1);
			chos[i]=0;
			chose[step]=0;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e18;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
