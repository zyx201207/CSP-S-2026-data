//freopen!!!!!
#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int> 
using namespace std;
const int N=1e5+10;
int c,t,n,n1,d,a[N],dis[N],way[N],ans;
int re[N],que[N]; 
vector<pi > g[N];
priority_queue<pi > q;
void build(int p,int l,int r){
	n1=max(n1,n+p);
	if(l==r){
		g[p+n].pb({l,1});
		return;
	}
	int mid=l+r>>1;
	int ls=p*2,rs=p*2+1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	g[p+n].pb({ls+n,0});
	g[p+n].pb({rs+n,0});
	return;
}
void update(int p,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		g[k].pb({p+n,0});
		return;
	} 
	int mid=l+r>>1;
	int ls=p*2,rs=p*2+1;
	if(ql<=mid) update(ls,l,mid,ql,qr,k);
	if(qr>mid) update(rs,mid+1,r,ql,qr,k);
	return;
}
void solve(){
	cin>>n>>d;n1=n;ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=1e5;i++) g[i].clear();
	for(int i=1;i<=n;i++) re[i]=1e18;
	int l,r;l=r=1;re[1]=0;que[1]=1;
	for(int i=2;i<=n;i++){
		while(l<=r&&a[i]-a[que[l]]>d) l++;
		if(l<=r) re[i]=re[que[l]]+1;
		while(l<=r&&re[i]<=re[que[r]]) r--;
		que[++r]=i;
	}
//	for(int i=1;i<=n;i++) cout<<re[i]<<' ';cout<<"\n";
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int l=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		update(1,1,n,i+1,l,i);
	}
//	for(int i=1;i<=n1;i++){
//		cout<<i<< "  ";
//		for(int j=0;j<g[i].size();j++) cout<<g[i][j].fi<<' ';//<<g[i][j].se<<'\n';
//		cout<<'\n';
//	}cout<<'\n';
	for(int s=1;s<=n;s++){
		for(int i=1;i<=n1;i++) dis[i]=1e18,way[i]=0;
		dis[s]=0,way[s]=1;
		q.push({0,s});
		while(!q.empty()){
			int u=q.top().se;q.pop();
	//		cout<<u<<' '<<dis[u]<<'\n';
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i].fi,w=g[u][i].se;
			//	if(v==4) cout<<u<<' '<<v<<' '<<dis[u]<<' '<<way[u]<<' '<<dis[v]<<' '<<way[v]<<'\n';
			//	if(v==2) cout<<u<< ' '<<dis[u]<<' '<<w<<'\n'; 
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					way[v]=way[u];
					q.push({dis[v],v});
				}
				else if(dis[v]==dis[u]+w){
					way[v]+=way[u];
					q.push({dis[v],v});
				} 
			}
		}
//		if(s==1)cout<<dis[4];
	//	cout<<s<<'\n';
		if(s!=1) continue;
		for(int i=s+1;i<=n;i++){
	//		cout<<dis[i]<<" "<<way[i]<<'\n';
			if(re[i]==dis[i]&&dis[i]!=1e18&&way[i]>=2) ans++;
		} 
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
//freopen!!!!!
/*

ohno I had two wrong ways and I code them for too long time
100+100+0+0=sb 
0 1 
4 2 
1 2 3 4 

0 2
4 2 
1 2 3 4 
5 2 
1 2 3 4 5

0 2 
5 3 
-2 -1 0 1 2 
6 2 
-4 -3 -2 -1 3 6
*/
