#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10,inf=1e18;
int c,n,m,d,q,ans;
int W[M],f[N][N];
bool vis[N];
vector<pair<int,int> > e[M];
vector<pair<int,int> > E[N];
priority_queue<pair<int,int>, vector<pair<int,int> >, less<pair<int,int> > > pq; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1,u,x,w;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>u>>w;
			e[u].push_back({i,w});
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){//m
		sort(e[i].begin(),e[i].end());
		for(int j=0;j<(int)e[i].size();j++){//d^2/2 
			for(int k=j+1;k<(int)e[i].size();k++){
				int a=e[i][j].first,val=e[i][j].second;
				int A=e[i][k].first,Val=e[i][k].second;
				if(val+Val<f[a][A]){
					f[a][A]=f[A][a]=val+Val;
					E[a].push_back({A,val+Val});
					E[A].push_back({a,val+Val});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		while(!pq.empty())pq.pop();
		for(int j=1;j<=n;j++)f[i][j]=inf,vis[j]=0;
		f[i][i]=0;
		pq.push({f[i][i],i});
		while(!pq.empty()){
			int t=pq.top().second;
			int tmp=pq.top().first;
			pq.pop();
			if(vis[t])continue;
			vis[t]=1;
			for(int j=0;j<E[t].size();j++){
				int a=E[t][j].first,val=E[t][j].second;
				if(f[i][t]+val<f[i][a]){
					f[i][a]=f[i][t]+val;
					pq.push({f[i][a],a});
				}
			}
		}
	} 
	while(q--){
		int u,v;
		ans=inf;
		cin>>u>>v;
		for(int j=0;j<(int)e[u].size();j++){//d
			for(int k=0;k<(int)e[v].size();k++){//d
				int a=e[u][j].first,val=e[u][j].second;
				int A=e[v][k].first,Val=e[v][k].second;
				if(a>A)swap(a,A);
				ans=min(ans,f[a][A]+val+Val); 
			}
		}
		cout<<ans+W[u]+W[v]<<"\n";
	}
	return 0;
}

