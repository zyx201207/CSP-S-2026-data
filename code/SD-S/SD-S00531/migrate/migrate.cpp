//csp-s2026 rp++
//noip2026 rp++
#include<bits/stdc++.h>
#define int long long
#define forr(i,a,n) for(int i=a;i<=n;i++)
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
vector<int> g[2000010];
int d[200010],sum[200010];
int x[200010];
priority_queue<pii,vector<pii>,greater<pii> > p;
void dij(int st,int d2) {
	p.push({d2,st});
	d[st]=0;
	while(!p.empty()) {
		pii uu=p.top();
		p.pop();
		int dd=uu.fi,u=uu.se;
		for(int v:g[u]) {
			if(d[u]+1<d[v]) {
				d[v]=d[u]+1;
				sum[v]=1;
			} else if(d[u]+1==d[v]) {
				sum[v]++;
			}
			
			if(d[v]>=d[u]+1) {
				p.push({d[v],v});
			}
		}
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,T;
	cin>>c>>T;
	while(T--) {
		int n,dma;
		cin>>n>>dma;
		forr(i,0,n) {
			g[i].clear();
			d[i]=1e18+10;
		}
		forr(i,1,n) cin>>x[i];
		int fl=1;
		forr(i,2,n-1){
			if(x[i]-x[i-1]!=x[i+1]-x[i]){
				fl=0;
				break;
			}
		}
		if(fl){
			int d3=x[2]-x[1];
			if(d3>dma){
				cout<<0<<'\n';
				return 0;
			}
			int ne=upper_bound
			(x+1,x+1+n,x[1]+dma)-x-1;
			int len=ne-1;
			if(len==1){
				cout<<0<<'\n';
				return 0;
			}
			if(n==1){
				cout<<0<<'\n';
				return 0;
			}
			int len2=len*2-1;
			int ans=n-len2+1;
			cout<<ans<<'\n';
			return 0;
		}
		
		forr(u,1,n) {
			forr(v,u+1,n) {
//			cout<<u<<' '<<v<<' '<<x[v]<<' '<<x[u]<<'\n';
				if(x[v]-x[u]<=dma) {
					g[u].pb(v);
				}
			}
		}
		int ans=0;
		forr(i,1,n) {
//			dfs1(i,0);
			dij(i,0);
			forr(j,i+1,n) {
//				cout<<"@"<<sum[j]<<' ';
				if(sum[j]==2) {
					ans++;
				}
			}
			forr(j,1,n) sum[j]=0,d[j]=1e18;
		}
		cout<<ans<<'\n';
	}//ccf给我点分。 
	return 0;
}
