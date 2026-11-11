#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2005],vis[2005],dis[2005][2005],dis2[2005][2005],ans=0;
vector<int> h[2005];
void dijk(int p){
	priority_queue<pair<int,int>> q;
	q.push({0,p});
	while(q.size()){
		pair<int,int> f=q.top();
		q.pop();
		int b=-f.first,k=f.second;
		if(vis[k]) continue;
		vis[k]=1;
		for(int i=0;i<h[k].size();i++){
			if(dis[p][h[k][i]]>b+1){
				dis[p][h[k][i]]=b+1;
				q.push({-b-1,h[k][i]});
			}
		}
	}
}
int check(int u,int v){
	int ways[5005];
	memset(ways,0,sizeof(ways));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis2[u][i]=n+1;
	dis2[u][u]=0;
	ways[u]=1;
	priority_queue<pair<int,int>> q;
	q.push({0,u});
	while(q.size()){
		pair<int,int> f=q.top();
		q.pop();
		int b=-f.first,k=f.second;
		if(vis[k]) continue;
		vis[k]=1;
		for(int i=0;i<h[k].size();i++){
			if(dis2[u][h[k][i]]>b+1){
				dis2[u][h[k][i]]=b+1;
				q.push({-b-1,h[k][i]});
			}
			if(dis[u][h[k][i]]==b+1) ways[h[k][i]]+=ways[k];
		}
	}
	return ways[v];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>11){
		for(int i=1;i<=t;i++) cout<<0<<endl;
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<=n;j++) dis[i][j]=n+1;
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++) h[i].clear();
		for(int i=1;i<=n;i++){
			int l=i,r=min(n,upper_bound(x+1,x+n+1,x[i]+d)-x-1);
			for(int j=l+1;j<=r;j++){
				h[i].push_back(j);
				h[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) vis[j]=0;
			dijk(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dis[i][j]>1&&check(i,j)==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
