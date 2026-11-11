#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N=5e5+10;
int n,m,d,q;
int t[N];
map<int,LL>dis[N];
vector<pair<int,LL>>g[N+500];
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++){
		int j=0;
		cin>>j;
		while(j--){
			LL a,t;
			cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		LL ans=t[x]+t[y];
		if(dis[x].count(y)){
			ans+=dis[x][y];
			cout<<ans<<endl;
			continue;
		}
		priority_queue<array<LL,2>>p;
		dis[x][x]=0;
		p.push({-0,x});
		while(!p.empty()){
			array<LL,2>d=p.top();
			p.pop();
			LL w=-d[0],u=d[1];
			if(dis[x].count(u)){
				if(w>dis[x][u])continue;
			}
			for(auto i:g[u]){
				int v=i.first;
				LL wn=w+i.second;
				if(!dis[x].count(v) || wn<dis[x][v]){
					dis[x][v]=wn;
					p.push({-wn,v});
				}
			}
		}
		ans+=dis[x][y];
		cout<<ans<<endl;
	}
	return;
}
int main(){
	fast;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	solve();
	return 0;
}
