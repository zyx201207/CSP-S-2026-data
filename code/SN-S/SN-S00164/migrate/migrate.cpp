/*
π˝¡ÀŒ“≥‘ ∫ 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>e[2000006];
int a[2000005],dis[2000005];
int c,t,n,d;
bool vis[2000006],sm[2000006];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&(a[j]-a[i])<=d)j++;
		if(i!=n)e[i].push_back(i+1);
		e[i].push_back(j-1);
	//	cout<<i<<' '<<i+1<<" "<<j-1<<'\n'; 
	}//cout<<endl;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	pq.push({0,1});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(dis[v]>(dis[u]+1)){
				dis[v]=dis[u]+1;
				pq.push({dis[v],v});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
	//	cout<<dis[i]<<' ';
		sm[dis[i]]++;
	}
	for(int i=1;i<=n;i++){
		ans+=dis[i]*(dis[i]-1)/2;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)e[i].clear();
	memset(sm,0,sizeof(sm));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve(); 
	return 0;
} 
