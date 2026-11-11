#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pll;
const int maxn=5e5+5;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
ll w[maxn];
vector<pll> at[505];
vector<pll> pr[maxn];
ll dis[maxn];
int u,v;
void ck(){
	memset(dis,inf,sizeof(dis));
	cin>>u>>v;
	dis[u]=0;
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	pq.push({dis[u],u});
	while(!pq.empty()){
		int nu=pq.top().second;
		pq.pop();
		for(auto i:pr[nu]){
			ll cn=i.second;
			for(auto j:at[i.first]){
				int a=j.first;
				ll t=j.second;
				if(dis[a]>dis[nu]+cn+t){
					dis[a]=dis[nu]+cn+t;
					pq.push({dis[a],a});
				}
			}
		}
		if(dis[v]<=inf)break;
	}
	cout<<w[u]+w[v]+dis[v]<<endl;
}
int main(){
	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			int a;
			ll t;
			cin>>a>>t;
			at[i].push_back({a,t});
			pr[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++)ck();
	fclose(stdin);
	fclose(stdout);
	return 0;
}