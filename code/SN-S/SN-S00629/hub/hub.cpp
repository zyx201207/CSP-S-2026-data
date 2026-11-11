#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
int c,t;
int n,k;
int u,v;
vector <int> g[N];
ll vis[N];
bool vv[N];
queue <int> que;
ll ans,maxn;

void dfs(){
	while(!que.empty()){
		int front=que.front(); que.pop();
		for(int i : g[front]){
			if(vv[i]) continue;
			vv[i]=true;
			vis[i]=min(vis[front]+1,vis[i]);
			que.push(i);
		}
	}
}

void init(){
	while(!que.empty()) que.pop();
	for(int i=1;i<=n;i++){
		vis[i]=INT_MAX-1000000;
		vv[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==2){
			ans=INT_MAX-1000000;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(j==i) continue;
					init();
					
					que.push(i);
					vis[i]=0;
					dfs();
					
					for(int i=1;i<=n;i++) vv[i]=false;
					while(!que.empty()) que.pop();
					
					que.push(j);
					vis[j]=0;
					dfs();
					ll maxn=-1;
					for(int i=1;i<=n;i++){
						maxn=max(maxn,vis[i]);
//						cout<<vis[i]<<" ";
					}
//					cout<<endl;
					ans=min(maxn,ans);
//					cout<<maxn<<endl;
				}
//				cout<<ans<<endl;
			}
			cout<<ans<<endl;
		}else{
			ans=INT_MAX-1000000;
			for(int i=1;i<=n;i++){
				for(int z=2;z<=k;z++){
					init();
					que.push(i);
					vis[i]=0;
					dfs();
					for(int j=1;j<=n;j++){
						if(j==i) continue;
						
						for(int i=1;i<=n;i++) vv[i]=false;
						while(!que.empty()) que.pop();
						
						que.push(j);
						vis[j]=0;
						dfs();
						ll maxn=-1;
						for(int i=1;i<=n;i++) maxn=max(maxn,vis[i]);
						ans=min(maxn,ans);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/ 
