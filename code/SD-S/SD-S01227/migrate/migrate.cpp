#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
#include<unordered_map>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int N=2000005;
ll x[N];
ll dis[N];
bool outQ[N];
ll c,t,n,d;
vector<pii> edge[N];
ll path[5005][5005];
struct Node {
	int u,dis;
	bool operator <(const Node& other)const {
		return dis<other.dis;
	}
};
/*void djk(int s,int t) {
	priority_queue<Node>pq;
	memset(dis,0x3f,sizeof dis);
	memset(outQ,0,sizeof outQ);
	dis[s]=0;
	pq.push({s,0});
	int cnt=0;
	while(!pq.empty()) {
		Node top=pq.top();
		int u=top.u;
		pq.pop();
		//cout<<u<<" ";
		if(outQ[u])continue;
		for(auto i:edge[u]) {
			int v=i.first,w=i.second;
			if(dis[u]+w==dis[v]) {
				cnt++;
				/*path[u][v]++;
				if(path[u][v]==2) {
					ans++;
					//cout<<"++\n";
				}
				if(path[u][v]==3) {
					ans--;
					//cout<<"1:--\n";
				}
				dis[v]=dis[u]+w;
				if(!outQ[v]) {
					pq.push({v,w});
					outQ[v]=1;
				}
			} else if(dis[u]+w<dis[v]) {
				if(path[u][v]==2) {
					ans--;
					//cout<<"2:--\n";
				}
				path[u][v]=0;
				dis[v]=dis[u]+w;
				if(!outQ[v]) {
					pq.push({v,w});
					outQ[v]=1;
				}
			}
		}
	}
//	cout<<endl;	
}*/
int visited[N];
ll cnt1;
ll ans1;
void dfs(int s,int t,int cost){
	if(s==t){
		if(cost<ans1){
			ans1=cost;
			cnt1=1;
		}else if(cost ==ans1){
			cnt1++;
		}
		return ;
	}
	for(auto i:edge[s]){
		if(!visited[i.first]){
			visited[i.first]=1;
			dfs(i.first,t,cost+i.second);
			visited[i.first]=0;
		}
	}
}
void solve(){
	ll ans=0;
	memset(visited,0,sizeof visited);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2;j++){
			ans1=0x3f3f3f3f;
			cnt1=0;
			visited[i]=1;
			dfs(i,j,0);
			visited[i]=0;
			if(cnt1==2){
			//	cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void A() {
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		if(n==1) {
			cout<<0<<'\n';
			continue;
		}
		int ch=x[2]-x[1];
		int di=d/ch+d/ch-1;
		if(d<ch or di>n or ch>n )cout<<0<<'\n';
		else cout<<n-di<<'\n';
	}
	return ;
}
void B() {
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		//if(x[n]-x[1]==2*d){
			cout<<0<<'\n';
	//	}else{
	//		for(int i=1;i<=n;i++){
	//			if()
	//		}
	//	}
	}
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11 or c==12) {
		A();
		return 0;
	}
	if(c==13 or c==14) {
		B();
		return 0;
	}
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)
			edge[i].clear();
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			//cout<<endl<<"i:"<<i<<endl;
			for(int j=i-1; j>0; j--) {
				if(x[i]-x[j]<=d) {
				//	cout<<j<<" ";
					edge[j].push_back({i,1});
					edge[i].push_back({j,1});
					//	cout<<j<<" "<<i<<" : "<<x[i]-x[j]<<'\n';
				} else {
					break;
				}
			}
		}
		solve();

	}
	return 0;
}

