#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=505;
const int M=5e5+5;
ll w[M],dis[N][N];
vector<int> a[N];
vector<ll> t[N];
int k[N];
struct Node{
	int x;
	ll t;
};
vector<Node> s[M];
void solve(){
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]].pb((Node){i,t[i][j]});
		} 
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		for(Node u:s[i]){
			for(Node v:s[i]){
				if(dis[u.x][v.x]==-1) dis[u.x][v.x]=u.t+v.t;
				else dis[u.x][v.x]=min(dis[u.x][v.x],u.t+v.t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==-1) continue;
			for(int j=1;j<=n;j++){
				if(dis[k][j]==-1) continue;
				if(dis[i][j]==-1) dis[i][j]=dis[i][k]+dis[k][j];
				else dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	int x,y;
	ll ans;
	while(Q--){
		cin>>x>>y;
		
		ans=-1;
		for(Node u:s[x]){
			for(Node v:s[y]){
				if(dis[u.x][v.x]==-1) continue;
				if(ans==-1) ans=u.t+v.t+dis[u.x][v.x];
				else ans=min(ans,u.t+v.t+dis[u.x][v.x]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}