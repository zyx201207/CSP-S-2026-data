#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2e6+5;
int c,t;
long long n,m,a[N];
long long dis[N];
vector<int >g[N]; 
long long ans;
bool b[N];
//bool dij(int st,int ed){
//	priority_queue<pair<long long ,int > ,vector<pair<long long,int > >,less<pair<long long ,int > > >q;
//	q.push({0,st});
//	rep(i,st,ed){
//		dis[i]=1e18;
//		b[i]=0;
//	}
//	int cnt=0;
//	dis[st]=0;
//	while(!q.empty()){
//		int u=q.top().second;
//		int w=q.top().first;
//		q.pop();
//		if(u>ed)continue;
//		if(w>dis[ed])continue;
//		if(b[u])continue;
//		b[u]=1;
//		for(auto v:g[u]){
//			if(v<ed)q.push({dis[v],v});
//			if(dis[v]>dis[u]+1){
//				dis[v]=dis[u]+1;
//				if(v==ed){
//					cnt=1;
//				} 
//				
//			}
//			else if(v==ed&&dis[u]+1==dis[v])cnt++;
//			if(dis[ed]==4&&v==ed)cout<<u<<' ';
//		}
//	}
//	return cnt==2;
//}
int anss,cnt;
void dij(int now,int sum,int st,int ed){
	if(now==ed){
		if(anss>sum){
			anss=sum,cnt=1;
		}else if(anss==sum)cnt++;
		return;
	}
	for(auto v:g[now]){
		dij(v,sum+1,st,ed);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n){
			rep(j,i+1,n){
				if(abs(a[j]-a[i])<=m)g[i].push_back(j);
			}
		}
		rep(i,1,n){
			rep(j,i+2,n){
				anss=1e9;
				cnt=0;
				dij(i,0,i,j);
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
		ans=0;
		rep(i,1,n)g[i].clear();
	}
	
	return 0;
}

