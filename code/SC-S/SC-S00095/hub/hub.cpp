#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T;
int n,k;
int u[N],v[N];
int dis[1005][1005];
vector<int> g[N];

int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool us[N];
bool hv[N];
int get(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		hv[i]=0;
		if((x>>(i-1))&1){
			us[i]=1;
			cnt++;
		}else{
			us[i]=0;
		}
		
	}
	if(cnt!=k) return 2e9;
	for(int i=1;i<n;i++){
		if(us[u[i]]&&us[v[i]]){
			fa[find(u[i])]=find(v[i]);
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(us[i]){
			if(!hv[find(i)]) cnt++;
			hv[find(i)]=1;
		}
	}
	if(cnt>2) return 2e9;
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=2e9;
		for(int j=1;j<=n;j++){
			if(us[j]){
				mn=min(mn,dis[i][j]);
			}
		}
		mx=max(mx,mn);
	}
	return mx;
}


queue<int> q;
void bfs(int x){
	q.push(x);
	while(q.size()){
		int tp=q.front();
		q.pop();
		for(int i:g[tp]){
			if(i!=x&&dis[x][i]==0){
				dis[x][i]=dis[x][tp]+1;
				q.push(i);
			}
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int ans=2e9;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0;
			}
			bfs(i);
		}
		if(c<=3){
			for(int i=1;i<(1<<n);i++){
				ans=min(ans,get(i));
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int mx=0;
					for(int k=1;k<=n;k++){
						mx=max(mx,min(dis[i][k],dis[j][k]));
					}
					ans=min(ans,mx);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}