#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d;
ll x[N];
void solve2(){
	cin >> n >> d;
	rep(i,1,n)
		cin >> x[i];
	ll f=x[2]-x[1];
	ll step=d/f;
	if(step==0){
		cout << 0 << '\n';
		return;
	}
	ll ans=0;
	rep(i,step+2,n){
		ll mn=step+1,mx=2*step-1;
		if(i-mx<1)mx=i-1;
		mn=max(mn,2*(step-1)+1);
		if(mx<mn)continue;
		ll cur=mx-mn+1;
		//cout << i << ":" << cur << '\n';
		ans+=cur;
	}
	cout << ans << '\n';
}
struct node{
	int dis,u;
	operator<(const node &k)const{
		return dis>k.dis;
	}
};
vector<vector<int>>e;
vector<int>dist,sc,th;
void dij(int s){
	priority_queue<node>q;
	dist.assign(n+1,0x3f3f3f3f);
	sc.assign(n+1,0x3f3f3f3f);
	th.assign(n+1,0x3f3f3f3f);
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().u,dis=q.top().dis;
		q.pop();
		if(dis>th[u])continue;
		for(auto v:e[u]){
			if(dis+1<dist[v]){
				sc[v]=dist[v];
				th[v]=sc[v];
				dist[v]=dis+1;
				q.push({dist[v],v});
			}
			else if(dis+1<sc[v]){
				th[v]=sc[v];
				sc[v]=dist[u]+1;
				q.push({sc[v],v});
			}
			else if((dis+1<th[v])){
				th[v]=dis+1;
				q.push({th[v],v});
			}
		}
	}
}
void solve(){
	if(c==0||c==11||c==12){
		solve2();
		return;
	}
	else if(c>12){
		cout << 0 << '\n';
		return;
	}
	cin >> n >> d;
	rep(i,1,n)
		cin >> x[i];
	rep(i,1,n){
		rep(j,1,i-1){
			if(x[i]-x[j]<=d){
				e[i].push_back(j);
			}
		}
	}
	ll ans=0;
	rep(i,1,n){
		dij(i);
		rep(j,1,i-1)
			if(dist[j]==sc[j]&&sc[j]!=th[j])
				ans++;
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> t;
	while(t--)
		solve();
	
	return 0;
}