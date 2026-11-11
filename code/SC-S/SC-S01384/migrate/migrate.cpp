#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+7;
int N,d,ans;
int In[MAXN];
int pos[MAXN];
int dis[MAXN];
int cnt[MAXN];
bool vis[MAXN];
queue <int> que;
vector <int> adj[MAXN];
void init(){
	for(int i=1;i<=N;i++)vis[i]=false,dis[i]=0,cnt[i]=0;
}
void Topsort(int S){
	init();
	vis[S]=true;
	que.push(S);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(int v:adj[u]){
			if(vis[v]){
				if(dis[v]==dis[u]+1)cnt[v]++;
				continue;
			}
			vis[v]=true;
			dis[v]=dis[u]+1;
			que.push(v);
		}
	}
}
set <pair <int,int>> st;
void solve(){
	cin>>N>>d;
	ans=0;
	st.clear();
	for(int i=1;i<=N;i++)adj[i].clear();
	for(int i=1;i<=N;i++)cin>>pos[i];
	for(int i=N;i>=1;i--){
		int pos1=upper_bound(pos+1,pos+1+N,pos[i]-d-1)-pos;
//		cout<<pos1<<'\n';
		int pos2=upper_bound(pos+1,pos+1+N,pos[i]+d)-pos-1;
//		cout<<pos2<<'\n';
		for(int j=pos1;j<i;j++)adj[i].push_back(j);
		for(int j=i+1;j<=min(N,pos2);j++)adj[i].push_back(j);
	}
//	for(int i=1;i<=N;i++){
//		cout<<i<<":\n";
//		for(int v:adj[i])cout<<v<<" ";
//		cout<<'\n';
//	}	
	for(int i=1;i<=N;i++){
		Topsort(i);
		for(int j=1;j<=N;j++){
			if(i==j)continue;
			if(cnt[j]==1){
//				cout<<i<<" "<<j<<'\n';
				if(i>j)st.insert({j,i});
				else   st.insert({i,j});
			}
		}
//		for(int i=1;i<=N;i++)cout<<dis[i]<<" ";
//		cout<<'\n';
	}
	cout<<st.size()<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/