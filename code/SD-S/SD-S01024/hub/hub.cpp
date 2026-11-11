#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,vis[1000005],vist[1000005],dis[1000005];
vector<int> g[1000005];
void dfs(int x,int fa,int val){
	vis[x]=1;
	for(int y:g[x]){
		if(y==fa) continue;
		if((val>>(y-1))&1) dfs(y,x,val);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){
			if(n==k){
				cout<<"0\n";
				for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
				continue;
			}
			int m=(n-1)/2;
			int l=(m+1)/2,r=m-l;
			int vl=(k+1)/2,vr=k-vl;
			if(vl>=l&&vr>=r){
				cout<<"1\n";
				for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
				continue;
			}
			int ans=max({(r-vr)/2+1,r-vr-(r-vr)/2+1,(l-vl)/2+1,l-vl-(l-vl)/2+1});
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
			continue;
		}
		int answ=1e9;
		for(int i=0;i<(1<<n);i++){
			int p=__builtin_popcount(i);
			if(p!=k) continue;
			int cnt=0;
			for(int j=1;j<=n;j++) if(((i>>(j-1))&1)&&(!vis[j])) ++cnt,dfs(j,0,i);
			if(cnt>2){
				for(int j=1;j<=n;j++) vis[j]=0;
				continue;
			}
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1) dis[j]=0,q.push({0,j});
				else dis[j]=1e9;
			}
			while(!q.empty()){
				int x=q.top().second;q.pop();
				if(vist[x]) continue;
				vist[x]=1;
				for(int y:g[x]){
					if(dis[y]>dis[x]+1){
						dis[y]=dis[x]+1;
						q.push({dis[y],y});
//						if(i==((1+(1<<3)))) cout<<x<<' '<<y<<'\n';
					}
				}
			}
			int ans=0;
			for(int j=1;j<=n;j++){
				ans=max(ans,dis[j]);
				vis[j]=0;
				vist[j]=0;
			}
//			for(int j=1;j<=n;j++) if(((i>>(j-1))&1)) cout<<j<<' ';
//			cout<<i<<' '<<cnt<<' '<<ans<<'\n';
			answ=min(answ,ans);
		}
		cout<<answ<<'\n';
		for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
	}
	return 0;
}

