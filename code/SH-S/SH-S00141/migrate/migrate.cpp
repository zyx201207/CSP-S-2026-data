#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;

ll c,n,dd,a[50005],indeg[50005],ind[50005],ans,d[50004],vis[50004];
vector<int> g[50004];

void solve(){
	ans=0;
	memset(indeg,0,sizeof(indeg));
	cin>>n>>dd;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=dd){
				g[j].push_back(i); 
			}
		}
	}
	for(int _u=1;_u<=n;_u++){
		memset(vis,0,sizeof(vis));
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		memset(d,0x3f,sizeof(d));
		d[_u]=0;
		map<int,int> mp;
		pq.push({0,_u});
		while(!pq.empty()){
			auto _=pq.top();
			pq.pop();
			int u=_.second;
			for(auto nxt:g[u]){
				int v=nxt;
				if(d[u]+1<d[v]){
					d[v]=d[u]+1;
					mp[v]=1;
					pq.push({d[v],v});
				}else if(d[u]+1==d[v]){
					mp[v]++;
					pq.push({d[v],v});
				}
			}	
		}
		for(int v=_u+1;v<=n;v++){
			if(mp[v]==2){
				ans++;
			}
		}
	}
//	cerr<<'\n';
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _T=1,c;cin>>c>>_T;
	while(_T--){
		solve();
	}
	return 0;
}
