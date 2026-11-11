#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e4+7,inf=2e18+7;
int sum[N];
int xx[N];
vector<PII>G[N];
int dis[N],vis[N];

priority_queue<PII,vector<PII>,greater<PII> >qq;

void dj(int st){
	qq.push({0,st});
	
	while(!qq.empty()){
		PII q1=qq.top();qq.pop();
		int sum=q1.first,u=q1.second;
		if(dis[u]<sum)continue;
		for(PII q2:G[u]){
			int v=q2.first,t=q2.second;
			if(dis[v]==sum+t)vis[v]++;
			if(dis[v]<sum+t)continue;
			dis[v]=sum+t;
			qq.push({sum+t,v});
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
//	if(c<=10){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)G[i].clear();
			for(int i=1;i<=n;i++)cin>>xx[i];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(xx[j]-xx[i]<=d)G[i].push_back({j,1});
				}
			}
		
		
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++)dis[j]=inf,vis[j]=0;
				dis[i]=0;
				dj(i);
				for(int j=i+1;j<=n;j++){
					if(vis[j]==1)ans++;
//					cout<<dis[j]<<" "<<vis[j]<<"\n";
				}
//				cout<<"\n";
			}
			
			cout<<ans<<"\n";
		}
//	}
	
	
	return 0;
}