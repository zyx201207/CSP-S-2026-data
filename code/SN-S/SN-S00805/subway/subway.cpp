// considering programming according to the little limit of d
// I have come up with an O(n^3) solution by using Floyd
// We can change the Floyd into the dijkstra so that we can speed up it
// green to blue question ,and the speed of it is O(md+n^2logn+q*d^2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
vector<ll> a[505],t[505];
ll k[505];
ll w[500005];
ll in1,in2;
ll mp[505][505];
vector<ll> tt[500005],tc[500005];
struct Edge{
	ll next,to,w;
}edge[1000000];
ll head[505],cnt;
void addEdge(ll from,ll to,ll w){
	edge[++cnt].to=to;
	edge[cnt].w=w;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
ll To[505][505],Get[505];
typedef pair<ll,ll> P;
void dijkstra(ll x){
	priority_queue<P,vector<P>,greater<P> > pq;
	memset(Get,0,sizeof Get);
	memset(To[x],0x3f,sizeof To[x]);
	To[x][x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		P pt=pq.top();
		pq.pop();
		if(Get[pt.second])continue;
		Get[pt.second]=true;
		for(ll i=head[pt.second];i;i=edge[i].next){
			if(To[x][edge[i].to]>To[x][pt.second]+edge[i].w){
				To[x][edge[i].to]=To[x][pt.second]+edge[i].w;
				pq.push({To[x][edge[i].to],edge[i].to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>in1>>in2;
			a[i].push_back(in1);
			t[i].push_back(in2);
			tt[in1].push_back(i);
			tc[in1].push_back(in2);
		}
	}//5e5
	memset(mp,0x3f,sizeof mp);
	ll MAXX=mp[0][0];
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k[i];j++){
			ll ja=a[i][j],jw=t[i][j];
			for(ll l=0;l<tt[ja].size();l++){
				ll la=tt[ja][l],lw=tc[ja][l];
				mp[i][la]=mp[la][i]=min(mp[i][la],jw+lw);
			}
		}
	}// 1e7
	for(ll i=1;i<=n;i++) mp[i][i]=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(mp[i][j]<MAXX){
				addEdge(i,j,mp[i][j]);
				addEdge(j,i,mp[i][j]);
			}
		}
	}//2.5e4
	for(ll l=1;l<=n;l++){
		dijkstra(l);
		for(ll i=1;i<=n;i++){
			mp[l][i]=To[l][i];
		}
	}//2.5e6
	while(q--){
		cin>>in1>>in2;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(ll i=0;i<tt[in1].size();i++){
			ll la=tt[in1][i],lw=tc[in1][i];
			for(ll j=0;j<tt[in2].size();j++){
				ll ja=tt[in2][j],jw=tc[in2][j];
				ans=min(ans,mp[la][ja]+lw+jw);
			}
		}
		cout<<ans+w[in1]+w[in2]<<'\n';
	}//4e7
	return 0;
}
