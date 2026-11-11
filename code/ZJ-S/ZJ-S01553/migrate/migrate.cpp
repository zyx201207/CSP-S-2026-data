#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,T;
int n,D;
const int N=2e6+5;
int a[N],cnt[N],d[N][3];
bool vis[N];
vector<int>g[N];
int bfs(int s){
	int res=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		d[i][0]=1e9+7;
		d[i][1]=1e9+7;
		d[i][2]=1e9+7;
	}
	queue<int>q;
	q.push(s);
	d[s][0]=0;
	d[s][1]=0;
	d[s][2]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
//			cout<<v<<endl;
			if(d[v][0]>d[u][0]+1){
				d[v][2]=d[v][1];
				d[v][1]=d[v][0];
				d[v][0]=d[u][0]+1;
				q.push(v);
			}else if(d[v][1]>=d[u][0]+1){
				d[v][2]=d[v][1];
				d[v][1]=d[u][0]+1;
			}else if(d[v][2]>=d[u][0]+1){
				d[v][2]=d[u][0]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<':'<<d[i][0]<<' '<<d[i][1]<<' '<<d[i][2]<<endl;
		if(d[i][0]==d[i][1] and d[i][1]!=d[i][2]){
			res++;
		}
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		map<pii,bool>mp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j and abs(a[i]-a[j])<=D and mp[{min(i,j),max(i,j)}]==0){
					g[i].push_back(j);
					g[j].push_back(i);
					mp[{min(i,j),max(i,j)}]=1;
//					cout<<i<<' '<<j<<endl;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
//		cout<<bfs(2)<<' ';
		cout<<ans/2<<'\n';
	}
	return 0;
}
