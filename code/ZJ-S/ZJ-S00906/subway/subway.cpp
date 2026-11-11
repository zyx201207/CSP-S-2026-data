#include<bits/stdc++.h>
using namespace std;
int n,d,q,c,m,w[520000],k,a[520000][5],t1,t2,vis[520000],cnt=1;
long long dd[520000],ans=1e17,sum[520000][25];
struct N{
	long long x,t,num,f;
	N(long long a,long long b,long long cc,long long ddd) : x(a),t(b),num(cc),f(ddd) {}
	bool operator < (const N &a) const {return t>a.t;}
};
vector<N> e[520000];
priority_queue<N> qq;
void bfs(int s,int end){
	for (int i=1;i<=n;i++) dd[i]=1e16,vis[i]=0;
	dd[s]=0,vis[s]=1;
	for (auto i:e[s]) qq.push({i.x,i.t,i.num,s});
	while (!qq.empty()){
		N tt=qq.top();qq.pop();
		if (tt.x==end){ans=min(ans,tt.t+sum[end][tt.num]);return;}
		if (tt.x>=ans) continue;
		for (auto i:e[tt.x]) if (i.x!=tt.f) qq.push({i.x,tt.t+(tt.num==i.num?0:i.t+sum[tt.x][tt.num]),i.num,tt.x});
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i=1;i<=n;i++) cin >> w[i];
	while (m--){
		cin >> k;
		for(int i=1;i<=k;i++){
			cin >> a[i][1] >> a[i][2];
			sum[a[i][1]][cnt]=a[i][2];
			if (i!=1) e[a[i][1]].push_back({a[i-1][1],a[i][2],cnt,0}),e[a[i-1][1]].push_back({a[i][1],a[i-1][2],cnt,0});
		}
		++cnt;
	}
	while (q--){
		cin >> t1 >> t2;
		ans=1e17;
		bfs(t1,t2);
		cout << ans+w[t1]+w[t2] << "\n";
	}
	return 0;
}
