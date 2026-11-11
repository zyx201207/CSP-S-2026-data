#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
vector<int>vec[5005];
int vis[5005];
int dis[5005];
queue<pair<int,int> >que;
void BFS(int x){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	while(!que.empty())que.pop();
	dis[x]=0;
	vis[x]=1;
	que.push({x,0});
	while(!que.empty()){
		pair<int,int> u=que.front();que.pop();
		if(u.second != dis[u.first])continue;
		for(int v:vec[u.first]){
			if(u.second + 1 <= dis[v]){
				if(dis[v]==0x3f3f3f3f3f3f3f3f)que.push({v,u.second+1});
				dis[v]=u.second+1;
				vis[v]+=vis[u.first];
			}
		}
	}
}
pair<int,int> dp[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c<=6){
			for(int i=1;i<=n;i++){
				vec[i].clear();
				for(int j=1;j<=n;j++){
					if(abs(x[i]-x[j]) <= d)vec[i].push_back(j);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				BFS(i);
				for(int j=1;j<=n;j++){
					if(vis[j]==2)ans++;
				}
			}
			cout<<ans/2<<'\n';
		}
		else if(c<=10){
			for(int i=1;i<=n;i++)vec[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j]) <= d)vec[j].push_back(i);
					dp[i][j]={0x3f3f3f3f3f3f3f3f,0};
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				dp[i][i]={0,1};
				for(int j=i+1;j<=n;j++){
					if(vec[j].empty())continue;
					dp[i][j]=dp[i][vec[j][0]];
					dp[i][j].first++;
					bool t=1;
					for(int v:vec[j]){
						if(t){t=0;continue;}
						if(dp[i][v].first + 1 > dp[i][j].first)break;
						dp[i][j].second += dp[i][v].second;
						if(dp[i][j].second > 2)break;
					}
					
					if(dp[i][j].second == 2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		if(c==11 || c==12){
			if(n==1)cout<<0<<'\n';
			else if(d < 2*(x[2]-x[1]))cout<<0<<'\n';
			else cout<<max(0ll,n-2*(d/(x[2]-x[1]))+1)<<'\n';
		}
		if(c==13 || c==14){
			int super=-1;
			if(n<=2){
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<= d && x[n]-x[i]<=d)super=i;
			}
			int ans=0;
			int tmp1=0;
			for(int i=1;i<super;i++){
				if(x[super+1]-x[i]>d)tmp1++;
			}
			x[0]=-0x3f3f3f3f3f3f3f3f;
			for(int i=super+1;i<=n;i++){
				if(x[i]-x[super-1]<=d && x[i]-x[super-2]>d)ans+=tmp1;
			}
			tmp1=0;
			for(int i=super+1;i<=n;i++){
				if(x[i]-x[super-1]>d)tmp1++;
			}
			x[n+1]=0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<super;i++){
				if(x[super+1]-x[i] <=d && x[super+2]-x[i] > d)ans+=tmp1;
			}
			cout<<ans<<'\n';
		}
	}
}
