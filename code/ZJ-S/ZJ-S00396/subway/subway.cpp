#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans,dp[500005];
int k[505],u[505][500005],w[500005];
bool vis[500005];
struct node{
	int x;
	long long t;
};
vector<node>a[500005];
map<pair<int,int>,int>mp;
map<pair<int,int>,long long>Ans;
struct Dij{
	int x;
	long long ti;
	bool operator <(const Dij &b)const{
		return ti>b.ti;
	}
};
void D(int st,int ed){
	priority_queue<Dij>q;
	dp[st]=w[st];
	vis[st]=1;
	q.push({st,w[st]});
	while(!q.empty()){
		Dij tmp=q.top();q.pop();
		int x=tmp.x;
		long long sum=tmp.ti;
		Ans[{st,x}]=sum;
		vis[x]=0;
		if(x==ed){
			ans=dp[x];
			return ;
		}
		for(node it:a[x]){
			int i=it.x;
			long long t=it.t;
			for(int j=1;j<=k[i];j++){
				int y=u[i][j];
				int ti=mp[{i,y}];
				if(y==x)continue;
				if(vis[y])continue;
				if(sum+t+ti<dp[y]||dp[y]==-1){
					dp[y]=sum+t+ti;
					q.push({y,dp[y]});
					vis[y]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u[i][j];
			long long x;cin>>x;
			mp[{i,u[i][j]}]=x;
			a[u[i][j]].push_back({i,x});
		}
	}
	while(q--){
		memset(dp,-1,sizeof dp);
		memset(vis,0,sizeof vis);
		int st,ed;
		cin>>st>>ed;
		if(Ans.count({st,ed})){
			cout<<Ans[{st,ed}]+w[ed]<<"\n";
			continue;
		}
		D(st,ed);
		cout<<ans+w[ed]<<"\n";
	}
	return 0;
}
