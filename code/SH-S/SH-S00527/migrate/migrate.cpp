#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<ll,ll>
const int N=1e6+5;
ll c,t,n,d;
ll dis[N],x[N],ans,cnt[N];
vector<pii> g[N];
void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
void dj(int s){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++)dis[i]=N,cnt[i]=0;
	dis[s]=0;cnt[s]=1;
	q.push({0,s});
	while(q.size()){
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(t.first!=dis[u])continue;
		for(auto j:g[u]){
			int v=j.first,w=j.second;
//			cout<<u<<' '<<v<<' '<<dis[u]<<' '<<dis[v]<<endl;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}else if(dis[v]==dis[u]+w){
//				cout<<"cnt++"<<u<<' '<<v<<' '<<cnt[u]<<' '<<cnt[v]<<' ';
				cnt[v]+=cnt[u];
//				cout<<cnt[v]<<endl;
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)add(i,j,1);
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
		for(int j=1;j<=n;j++){
			if(i==j)continue;
//			cout<<i<<' '<<j<<' '<<cnt[i]<<endl;
			if(cnt[j]==2){
				ans++;
//				cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans/2<<endl;
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	
	return 0;
} 

