#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MX=2e6+1;
int c,t,d,n,dis[MX],cnt[MX],x[MX];
vector<int> e[MX];
void bfs(int s){
	for(int i=1;i<=n;++i){
		dis[i]=MX;
		cnt[i]=0;
	}
	cnt[s]=1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;++i)
		e[i].clear();
	sort(x+1,x+1+n);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(abs(x[i]-x[j])<=d){
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	int sm=0;
	for(int i=1;i<=n;++i){
		bfs(i);
		for(int j=1;j<=n;++j){
			if(cnt[j]==2ll){
				++sm;
			}
		}
	}
	cout<<(sm/2)<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		solve1();
	}
	return 0;
}

