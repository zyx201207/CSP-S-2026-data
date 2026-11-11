#include<bits/stdc++.h>
using namespace std;

#define ll long long


const int N=2e6+9;
int c,t;
ll n,d,x[N],dis[N],cnt[N];
vector <int> g[N];

void bfs(int s){
	queue <int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	memset(dis,0x7f,sizeof(dis));
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v<u) continue;
			if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
			}
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
				cnt[v]=cnt[u];
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cnt[i]=1;
			g[i]={};
		}
		for(int i=1;i<=n;i++){
			cin >> x[i];
			for(int j=1;j<=i;j++){
				ll w=abs(x[i]-x[j]);
				if(w <= d && w){
					g[i].push_back(j);
					g[j].push_back(i);
				} 
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++){
				cnt[i]=0;
			}
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				} 
				//	cout << "!"<<i<<" "<<j<<" "<< cnt[j]<<endl; 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


//求最短路个数 
