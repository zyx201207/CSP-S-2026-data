#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],vis[2000005],dis[2000005],ans;
vector<int>ve[2000005];
map<int,int>mp;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void solve(){
	for(int i=0;i<=2000001;i++){
		ve[i].clear();
	}
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				ve[i].push_back(j);
				ve[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof(dis));
		q.push({0,i});
		dis[i]=0;
		mp.clear();
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			for(auto v:ve[u]){
				if(dis[v]==dis[u]+1){
					mp[v]++;
					dis[v]=dis[u]+1;
					q.push({dis[v],v});
				}
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					mp[v]=0;
					q.push({dis[v],v});
				}
			}
		}
		for(auto j:mp){
			if(j.second==1){
				ans++; 
			}
		}
	}
	cout<<ans/2<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

