#include<bits/stdc++.h>
using namespace std;
long long g[550][550];
long long w[550];
vector<pair<long,long>> j[500500];
long long c,n,m,d,q;
void dfs(long long l){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
	long long mark[550]={0};
	for(long long i=1;i<=n;i++){
		q.push({g[l][i],i});
	}
	while(!q.empty()){
		long long x=q.top().first;
		long long y=q.top().second;
		if(mark[y]==1)q.pop();
		for(long long i=1;i<=n;i++){
			g[l][i]=min(g[l][i],x+g[y][i]);
			g[i][l]=min(g[i][l],x+g[y][i]);
		}
		mark[y]=1;
		q.pop();
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long f=1;f<=k;f++){
			long long a,t;
			cin>>a>>t;
			if(!j[a].empty()){
				for(auto e:j[a]){
					g[i][e.first]=min(e.second+t,g[i][e.first]);
					g[e.first][i]=min(e.second+t,g[i][e.first]);
				}
			}
			j[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)dfs(i);
	for(int i=1;i<=q;i++){
		long long l,r,ans=1e18;
		cin>>l>>r;
		for(auto e:j[l]){
			for(auto f:j[r]){
				if(f.first==e.first){
					long long qq=e.second+f.second;
					ans=min(ans,qq);
				}
				ans=min(ans,g[e.first][f.first]+e.second+f.second);
			}
		}
		cout<<ans+w[l]+w[r]<<endl; 
	}
	return 0;
} 
