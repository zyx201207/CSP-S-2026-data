#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+7;
bool vis[N];
int dis[N],ans[N],a[N];
vector<pair<int,int> > g[N];
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,x});
	while(!pq.empty()){
		auto t=pq.top();pq.pop();
		vis[t.second]=true;
		for(auto i:g[t.second]){
			if(!vis[i.first]){
				if(dis[i.first]>t.first+i.second){
					ans[i.first]=0;
					dis[i.first]=t.first+i.second;
					pq.push({dis[i.first],i.first});
				}
				if(dis[i.first]==t.first+i.second){
					ans[i.first]++;
				}
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int aa=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			g[i].clear();
			cin>>a[i];
			int j=i-1;
			while(a[i]-a[j]<=d && j>0){
				g[i].push_back({j,1});
				g[j].push_back({i,1});
				j--;
			}
		}
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			memset(ans,0,sizeof(ans));
			dis[i]=0;
			vis[i]=true;
			dij(i);
			for(int j=i;j<=n;j++){
				if(ans[j]==2)aa++;
			}
		}
		cout<<aa<<endl;
	}
}
