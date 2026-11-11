#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll c,T,n,d;
ll x[N],dis[N],cnt[N],vis[N];
vector<ll> to[N];
struct Edge{ll to,nxt;
}e[N];
ll nE,hd[N];
void add(ll u,ll v){
	e[++nE]=(Edge){v,hd[u]};
	hd[u]=nE;
}
struct Node{
	ll u,c; 
	bool operator<(const Node&a)const{
		return a.c>c;
	}
};
ll bfs(ll S,ll T){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	q.push((Node){S,0});
	dis[S]=0,cnt[S]=1;
	while(!q.empty()){
		//cout<<"2"<<endl;
		Node nw=q.top();q.pop();
		if(vis[nw.u]) continue;
		vis[nw.u]=1;
		for(ll i=hd[nw.u];i;i=e[i].nxt){
			ll v=e[i].to;
			if(dis[v]>dis[nw.u]+1){
				dis[v]=dis[nw.u]+1;
				cnt[v]=cnt[nw.u];
				q.push((Node){v,dis[v]});
			}
			else if(dis[v]==dis[nw.u]+1){
				cnt[v]+=cnt[nw.u];
				q.push((Node){v,dis[v]});
			}
		}
	}
	//for(ll i=1;i<=n;i++) cout<<cnt[i]<<" ";
	//cout<<endl;
	//for(ll i=1;i<=n;i++) cout<<dis[i]<<" ";
	//cout<<endl;
	return cnt[T];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++) cin>>x[i];
			cout<<n-d/abs(x[2]-x[1])<<endl;
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		memset(hd,0,sizeof(hd));
		nE=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1+i;j<=n;j++){
				if(abs(x[i]-x[j])>d) break;
				add(i,j);
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(bfs(i,j)==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
				
