#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
pair<int,int> p[1000010];
int Fa[100010];
int f(int x){
	return Fa[x]==x?x:Fa[x]=f(Fa[x]); 
}
queue<int> q;
int dis[200010];
bool vis[200010];
		int n,k;
void bfs(){
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto to:v[x]){
			if(vis[to])continue;
			vis[to]=1;
			dis[to]=dis[x]+1;
			q.push(to);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
			p[i]={x,y};
		}
		int ans=0x3f3f3f3f;
		for(int o=0;o<(1<<n);o++){
			for(int i=1;i<=n;i++)Fa[i]=i,vis[i]=0;;
			for(int i=1;i<n;i++){
				int x=p[i].first,y=p[i].second;
				if((o&(1<<x-1)) && (o&(1<<y-1)))Fa[f(x)]=f(y);
				
			}
			int cnt=0,cntt=0;
			for(int i=1;i<=n;i++){
				if(!(o&(1<<i-1)))continue;
				if(Fa[i]==i)cnt++;
				cntt++;
			}
			if(cnt>2 || cntt!=k)continue;
			for(int i=1;i<=n;i++){
				if(!(o&(1<<i-1)))continue;
				vis[i]=1;
				dis[i]=0;
				q.push(i);
			}
			bfs();
			int mx=0;
			for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
			ans=min(ans,mx);
		}
		cout << ans << endl;
	
	}
	return 0;
}
