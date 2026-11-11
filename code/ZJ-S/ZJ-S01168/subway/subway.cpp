#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+10,M=550;
int cnt[N];
int s[N],vis[N],st[N],en[N],dis[N];
int c,n,m,d,q;
map<int,int> mp[N];
map<int,map<int,int> > sum;
struct node{
	int v;
	int w;
};
struct Node{
	int u;
	int w;
	bool operator < (const Node &b) const{
		return b.w<w;
	}
};
vector<node> ve[N];
priority_queue<Node> qu;
queue<node> qq;
void dj(int st){
	qu.push({st,0});
	dis[st]=0;
	while(!qu.empty()){
		int u=qu.top().u;
		//cout<<u<<" "<<qu.top().w<<endl;
		qu.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(mp[u].count(st)){
			sum[st][u]=dis[u];
			cnt[st]--;
		}
		if(!cnt[st]) return ;
		for(auto x:ve[u]){
			int v=x.v;
			int w=x.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				qu.push({v,dis[v]});
			}
		}
	}
}
void bf(int st){
	qq.push({st,0});
	while(!qq.empty()){
		int u=qq.front().v;
		int w=qq.front().w;
		//cout<<u<<" "<<qu.top().w<<endl;
		qq.pop();
		//if(mp[u].count(st)){
		//	sum[st][u]=w;
		//}
		//cnt++;
		//if(cnt==m+n) return ;
		for(auto x:ve[u]){
			int v=x.v;
			int wi=x.w;
			if(vis[v]) continue;
			vis[v]=1;
			qq.push({v,w+wi});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		int k,u=i+m;
		cin>>k;
		for(int i=1;i<=k;i++){
			int v,w;
			cin>>v>>w;
			ve[u].push_back({v,w});
			ve[v].push_back({u,w});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st[i]>>en[i];
		for(auto x:ve[st[i]]) mp[en[i]][x.v]=1,cnt[x.v]++;
	}
	if(16<=c && c<=19){
		for(int i=1;i<=n;i++){
			//cnt=0;
			while(!qq.empty()) qq.pop();
			//memset(dis,0x3f3f3f3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			int s=i+m;
			bf(s);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			//cnt=0;
			while(!qu.empty()) qu.pop();
			memset(dis,0x3f3f3f3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			int s=i+m;
			dj(s);
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0x3f3f3f3f;
		for(auto x:ve[st[i]]){
			ans=min(ans,x.w+sum[x.v][en[i]]);
		}
		cout<<ans+s[st[i]]+s[en[i]]<<endl;
	}
	
}
/*
5 5
1 2 4 8 9
*/

