#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e6+27;
const int MAXNME=5e3+27;
const long long MAXD=2e18+27;
const int INFME=1e9+7;

int n;
long long d;
long long x[MAXN];
int dist[MAXN],vis[MAXN],rem[MAXN];
vector<pair<int,int> > cnt[MAXN];

vector<int> g[MAXN];
set< pair<int,int> > st;

inline void bfs(int start){
//	cout<<start<<endl;
	for(int i=1;i<=n;i++) dist[i]=INFME,vis[i]=0,rem[i]=0,cnt[i].clear();
	priority_queue< pair<int,int> ,vector< pair<int,int> > ,greater< pair<int,int> > > que;
	dist[start]=0;
	que.push({0LL,start});
	
	while(!que.empty()){
		int u=que.top().second;
		que.pop();
//		cout<<"    "<<u<<":"<<endl;
		if(vis[u]>=2) continue;
		vis[u]++;
		
		for(auto v:g[u]){
//			cout<<"        "<<v<<" "<<vis[v]<<" "<<rem[v]<<" "<<dist[v]<<" "<<dist[u]+1<<endl;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				cnt[v].push_back({u,1});
				rem[v]=1;
				if(vis[v]<2) que.push({dist[v],v});
			}
			else if(dist[v]==dist[u]+1){
				bool flag=true;
				for(int i=0;i<cnt[v].size();i++){
					if(cnt[v][i].first==u){
						rem[v]+=rem[u]-cnt[v][i].second;
						cnt[v][i].second=rem[u];
						flag=false;
						break;
					}
				}
				if(flag){
					cnt[v].push_back({u,rem[u]});
					rem[v]+=rem[u];
				}
				que.push({dist[v],v});
			}
		}
		
	}
//	cout<<"    "<<start<<":"<<endl<<"    ";
	for(int i=1;i<=n;i++){
//		cout<<"    "<<rem[i]<<" ";
		if(i==start) continue;
		if(rem[i]==2) st.insert({min(i,start),max(i,start)});
	}
//	cout<<endl;
	
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int c,T;
	cin>>c>>T;
	
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			long long tmp=x[2]-x[1];
			long long ans=0;
			if(d<=tmp) cout<<"0"<<endl;
			else{
				if(d%tmp==0) d/=tmp;
				else d=d/tmp-1;
				if(d==1){
					cout<<0<<endl;
					continue;
				}
//				cout<<d<<endl;
				for(int w=1;w<=n;w++){
					if(w>d&&(w-1)%d!=0){
						ans+=(n-w+1);
						break;
					}
				}
				cout<<ans<<endl;
			}
		}
		return 0;
	}
	
	while(T--){
		
		for(int i=1;i<=n;i++) g[i].clear();
		st.clear();
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
			
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(x[j]-x[i]<=d) cout<<i<<" "<<j<<endl;
//			}
//		}
			
//		cout<<d<<" "<<x[4]-x[1]<<endl;
		int l=1,r=1;
		for(int i=1;i<=n;i++){
			while(r+1<=n&&x[r+1]-x[i]<=d) r++;
			while(l+1<=i&&x[i]-x[l]>d) l++;
			for(int j=l;j<=r;j++){
				if(j==i) continue;
				g[i].push_back(j);
			}
		}
		
//		for(int i=1;i<=n;i++){
//			cout<<i<<":";
//			for(auto v:g[i]) cout<<v<<" ";
//			cout<<endl;
//		}
		
		for(int i=1;i<=n;i++)	
			bfs(i);
//		for(auto e:st){
//			cout<<e.first<<" "<<e.second<<endl;
//		}
		cout<<st.size()<<endl;
	}

	return 0;
}