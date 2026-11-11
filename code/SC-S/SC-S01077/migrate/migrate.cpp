#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
const int inf=1e9+7;
int n,cnt[maxn];
__int128 plac[maxn],d;
long long ans;
vector<int> g[maxn];

void read(__int128 &x){
	x=0;
	string s;cin>>s;
	int len=s.length();
	int jud=0;
	if(s[0]=='-'){
		jud=1;
	}
	for(int i=jud;i<len;i++){
		__int128 idx=s[i]-'0';
		x=x*10;x+=idx;
	}
	if(jud) x=0-x;
}

void make_edge(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//cout<<i<<" "<<j<<" "<<(long long)(plac[j]-plac[i])<<'\n';
			if(plac[j]-plac[i]>d) break;
			g[i].push_back(j);
			g[j].push_back(i);
			//cout<<i<<" "<<j<<" "<<(long long)(plac[j]-plac[i])<<'\n';
		}
	}//cout<<'\n';
}

int vis[maxn];
long long dis[maxn];
void dijkstra(int s){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	for(int i=1;i<=n;i++){
		cnt[i]=vis[i]=0;dis[i]=inf;
	}
	dis[s]=0;
	pq.push({0,s});
	while(pq.size()){
		auto e=pq.top();pq.pop();
		int u=e.second;long long w=e.first;
		//cout<<u<<" "<<w<<'\n';
		if(vis[u]){
			//if(u==s) continue;
			if(w==dis[u]){
				//cout<<s<<" "<<u<<'\n';
				cnt[u]++;
				if(cnt[u]==1) ans++;
				if(cnt[u]==2) ans--;
			}
			//continue;
		}
		vis[u]=1;
		//cout<<"u="<<u<<'\n';
		//cout<<"enter v= ";
		for(auto v:g[u]){
			//if(!vis[v]){
				if(dis[v]>=dis[u]+1){
					//cout<<v<<" ";
					dis[v]=dis[u]+1;
					pq.push({dis[v],v});
				}
			//}
		}//cout<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n;read(d);
		for(int i=1;i<=n;i++){
			read(plac[i]);
		}
		make_edge();
		for(int i=1;i<=n;i++){
			//cout<<"now: "<<i<<'\n';
			dijkstra(i);
		}
		cout<<ans/2<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
		ans=0;
	}
	
	return 0;
}