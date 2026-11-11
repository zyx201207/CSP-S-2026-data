#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>
int c,t;
int n,d;
int a[2000010];
int ans;
struct node{
	int v,w;
};
vector<node> e[5010];
priority_queue<P,vector<P>,greater<P> > q;
int dis[5010];
int vis[5010];
int cnt[5010];
void dijk(int st){
	fill(dis+1,dis+1+n,0x3f3f3f3f);
	fill(vis+1,vis+1+n,0);
	fill(cnt+1,cnt+1+n,0);
	dis[st]=0;
	cnt[st]=1;
	q.push({0,st});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(node i:e[u]){
			if(dis[i.v]==dis[u]+i.w) cnt[i.v]+=cnt[u];
			else if(dis[i.v]>dis[u]+i.w){
				dis[i.v]=dis[u]+i.w;
				cnt[i.v]=cnt[u];
				q.push({dis[i.v],i.v});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d==1) cout<<0<<'\n';
		int l=max(0ll,1-a[1]);
		for(int i=1;i<=n;i++) a[i]+=l;
		if(n<=5000){
			for(int i=0;i<=n;i++) e[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) break;
					else e[i].push_back({j,1});
				}
			}
			for(int i=1;i<=n;i++){
				dijk(i);
				for(int j=1;j<=n;j++){
					if(cnt[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else if(d>=(a[n]-a[1])){
			cout<<0<<'\n';
			continue;
		}
		else{
			int f=1;
			int D=a[2]-a[1];
			for(int i=3;i<=n;i++){
				if(a[i]-a[i-1]!=D){
					f=0;
					break;
				}
			}
			if(f){
				if(D<d) cout<<n-2*d/D+1<<'\n';
				else cout<<0<<'\n';
			}else cout<<0<<'\n';
		}
	}
	return 0;
}
