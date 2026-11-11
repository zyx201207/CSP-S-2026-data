#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e6+5;

int n;
ll D,ans;

ll a[N];

vector<pair<int,ll>> G[N];

bool vis[N];
ll dis[N],cnt[N];

struct wcy{
	int u;
	ll d;
	
	bool operator <(wcy x) const{
		return d>x.d;
	}
};

void dijkstra(int s){
	fill(vis+1,vis+n+1,0);
	fill(cnt+1,cnt+n+1,0);
	fill(dis+1,dis+n+1,LLONG_MAX);
	
	priority_queue<wcy> qu;
	
	dis[s]=0; cnt[s]=1;
	qu.push({s,0});
	
	while(!qu.empty()){
		wcy nw=qu.top(); qu.pop();
		
		int u=nw.u;
		ll d=nw.d;
		
		if(vis[u]) continue;
		vis[u]=1;
		
		for(auto it:G[u]){
			int v=it.first;
			ll w=it.second;
			
			if(w>D){
				continue;
			}
			
			if(d+1<dis[v]){
				dis[v]=d+1; cnt[v]=cnt[u];
				qu.push({v,d+1});
			}else if(d+1==dis[v]) cnt[v]+=cnt[u];
		}
	}
	
	for(int i=1;i<=n;i++){
		if(cnt[i]==2) ans++;
	}
}

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int c,T; cin>>c>>T;
	
	if(11<=c&&c<=12){
		while(T--){
			cin>>n>>D;
			for(int i=1;i<=n;i++) cin>>a[i];
			
			D/=(a[2]-a[1]);
			
			cout<<n-D*2+1;
		}
	}else{
		while(T--){
			cin>>n>>D;
			
			for(int i=1;i<=n;i++){
				cin>>a[i];
				for(int j=1;j<i;j++) G[j].push_back({i,a[i]-a[j]});
			}
			
			for(int i=1;i<=n;i++) dijkstra(i);
			
			cout<<ans<<endl;
			
			ans=0;
			for(int i=1;i<=n;i++) G[i].clear();
		}
	}

	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
9 7
1 3 5 7 9 11 13 15 17

*/
