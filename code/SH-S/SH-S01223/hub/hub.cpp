#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int const N=505,M=500005;
vector<pair<int,int>> v[N+M];
bool vis[N+M];
ull f[N+M];

void bfs(int x,int y){
	priority_queue<pair<int,int>> que;
	f[x]=0;
	que.push({0,x});
	while(que.size()){
		pair<int,int> awa=que.top();
		que.pop();
		for(pair<int,int> i : v[awa.second]){
			if(f[i.second]>f[awa.second]+i.first){
				f[i.second]=f[awa.second]+i.first;
				que.push(i);
			}
		}
	}
}

int main(){
	freopen("hub.in ","r",stdin);
	freopen("hub.out ","w",stdout);
	int c,m,n,d,q,w[M];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a+N].push_back({t,i});
			v[i].push_back({t,a+N});
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		memset(f,0x3f,sizeof(f));
		int x,y;
		cin>>x>>y;
		bfs(x+N,y+N);
		cout<<f[y+N]+w[x]+w[y]<<'\n';
	}
	return 0;
}
