#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+10;
int c,t,n,d,touch[maxn],f[maxn];
ll arr[maxn],ans,dis[maxn];
bool vis[maxn];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>qp;
void dj(int u){
	dis[u]=0;
	qp.push({0,u});
	while(!qp.empty()){
		auto v=qp.top();
		qp.pop();
		if(v.first<dis[v.second])continue;
		vis[v.second]=1;
		for(int i=v.second+1;i<=v.second+touch[v.second];i++){
			if(dis[i]==dis[v.second]+1)f[i]++;
			else if(dis[i]>dis[v.second]+1){
				qp.push({dis[v.second+1],i});
				f[i]=1;
				dis[i]=dis[v.second]+1;
			}
		}	
	}
}
void read(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dis,127,sizeof(dis));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		int l=1;
		for(int i=1;i<=n;i++){
			while(arr[i]-arr[l]>d){
				touch[l]=i-l;
				l++;
			}
		}
		for(;l<=n;l++){
			touch[l]=n-l;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i])dj(i);
			if(f[i]==2)ans++;
		}
		cout<<ans<<"\n";
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	
	return 0;
}