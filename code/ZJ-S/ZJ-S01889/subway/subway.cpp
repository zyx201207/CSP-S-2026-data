#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
const int maxm=1e3+5;
const int maxd=25;
const int maxe=4e5+5;
struct node{
	ll v;
	ll w;
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};
ll c;
ll m,w[maxm];
ll n;
ll k[maxn];
ll a[maxn][maxd];
ll t[maxn][maxd];
ll d;
ll q;
vector<node> e[maxe];
ll f_id[maxm];
ll l,r;
bool vis[maxe];
ll ans;
ll bfs(){
	memset(vis,false,sizeof(vis));
	priority_queue<node> q;
	q.push({l,0});
	vis[l]=true;
	ans=1e15;
	while (!q.empty()){
		node fr=q.top();
		q.pop();
		ll pos=fr.v,dis=fr.w;
		if (pos==r){
			ans=min(ans,dis);
			continue;
		}
		for (auto &i:e[pos]){
			ll next_pos=i.v,w=i.w;
			if (vis[next_pos]) continue;
			q.push({next_pos,dis+w});
			vis[next_pos]=true;
		}
	}return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++){
		cin>>w[i];
		e[i].push_back({i+m,w[i]});
		e[i+m].push_back({i,w[i]});
		f_id[i]=2;
	}
	for (ll i=1;i<=n;i++){
		cin>>k[i];
		for (ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ll exit=a[i][j],station=exit+m;
			ll point=exit+f_id[exit]*m;
			f_id[exit]++;
			e[station].push_back({point,t[i][j]});
			e[point].push_back({station,t[i][j]});
		}
		for (ll o=1;o<=k[i];o++){
			for (int p=1;p<=k[i];p++){
				if (o==p) continue;
				ll exito=a[i][o],exitp=a[i][p];
				ll pointo=exito+(f_id[exito]-1)*m;
				ll pointp=exitp+(f_id[exitp]-1)*m;
				e[pointo].push_back({pointp,0});
			}
		}
	}
	while (q--){
		cin>>l>>r;
		cout<<bfs()<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}