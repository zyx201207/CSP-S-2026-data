#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int const N=505,M=20005;
vector<pair<int,int>> v[N+M];
bool vis[N][N+M];
ull f[N][N+M];

void bfs(int x){
	priority_queue<pair<int,int>> que;
	f[x][x]=0;
	que.push({0,x});
	while(que.size()){
		pair<int,int> awa=que.top();
		que.pop();
		if(vis[x][awa.second]) continue;
		vis[x][awa.second]=true;
		for(pair<int,int> i : v[awa.second]){
			if(!vis[x][i.second]&&f[x][i.second]>=f[x][awa.second]+i.first){
				f[x][i.second]=f[x][awa.second]+i.first;
				que.push({f[x][i.second],i.second});
			}
		}
	}
}

int main(){
	memset(f,0x3f,sizeof(f));
	freopen("subway.in ","r",stdin);
	freopen("subway.out ","w",stdout);
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
			f[i][a+N]=t;
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ull ans=f[1][x+N]+f[1][y+N];
		for(int i=2;i<=n;i++){
			ans=min(ans,f[i][x+N]+f[i][y+N]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
