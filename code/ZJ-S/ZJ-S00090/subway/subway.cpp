#include<bits/stdc++.h>
using namespace std;
struct stk{
	int id,time;
};
int w[500005];
vector<stk> a[505];
struct node{
	int id;
	long long w;
	bool operator <(const node x) const{
		return w < x.w;
	}
};
long long dis[1005][1005];
vector<int> v[500005];
bool vis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,n,m,D,Q;
	cin>>C>>n>>m>>D>>Q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1,x,y;i <= n;i++){
		cin>>x,a[i].push_back({x,0});
		for(int j = 1;j <= a[i][0].id;j++){
			cin>>x>>y,a[i].push_back({x,y});
		}
	}
	if(C >= 12&&C <= 19){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= a[i][0].id;j++){
				for(int k = 1;k <= a[i][0].id;k++){
					if(j != k){
						v[j].push_back(k);
						v[k].push_back(j);
					}
				}
			}
		}
		while(Q--){
			memset(vis,false,sizeof(vis));
			int x,y;
			cin>>x>>y;
			long long ans = w[x]+w[y];
			queue<node> q;
			q.push({x,0});
			while(!q.empty()){
				node t = q.front();
				q.pop();
				if(t.id == y){
					ans += t.w*a[1][1].time;
					break;
				}
				for(int it:v[t.id]){
					if(!vis[it]){
						vis[it] = true;
						q.push({it,t.w+1});
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i][0].id;j++){
			for(int k = 1;k <= a[i][0].id;k++){
				if(j != k){
					dis[a[i][j].id][a[i][k].id] = min(dis[a[i][j].id][a[i][k].id],(long long)a[i][j].time+a[i][k].time);
					dis[a[i][k].id][a[i][j].id] = min(dis[a[i][k].id][a[i][j].id],(long long)a[i][j].time+a[i][k].time);
				}
			}
		}
	}
	for(int k = 1;k <= m;k++){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
