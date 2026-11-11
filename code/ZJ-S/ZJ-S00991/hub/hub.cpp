#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
const int N=2e6+7;
const int M=1e6+7;
int C,n,k,d;
int a[N],dep[N],f[N],b[N],dl[N],dr[N],fl[N],fr[N],vis[N];
vector<int>e[N];
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[d])d=u;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void dfsl(int u,int fa){
	fl[u]=fa;
	dep[u]=dep[fa]+1;
	dl[u]=dep[u];
	for(auto v:e[u]){
		if(v==fa)continue;
		dfsl(v,u);
	}
}
void dfsr(int u,int fa){
	fr[u]=fa;
	dep[u]=dep[fa]+1;
	dr[u]=dep[u];
	for(auto v:e[u]){
		if(v==fa)continue;
		dfsr(v,u);
	}
}
int check(int x){
	d=1;
	dep[0]=-1;
	dfs(1,0);
	int rt=d;
	dfs(rt,0);
	vector<int>p;
	int now=d;b[now]=1;
	p.push_back(now);
	while(now!=rt){
		now=f[now];
		b[now]=1;
		p.push_back(now);
	}
	if(x>=(int)p.size()/2)return 1;
	int l=p[x],r=p[(int)p.size()-x-1];
	dfsl(l,0);
	dfsr(r,0);
	int flag=1,nk=2;
	for(int i=1;i<=n;i++)vis[i]=0;
	vis[l]=vis[r]=1;
	for(int i=1;i<=n;i++){
		if(dl[i]>x&&dr[i]>x){
			int p=i,dis=0,lk=0,rk=0;
			while(p!=l){
				dis++;p=fl[p];
				if(dis>=x&&!vis[p]){
					lk++;
				}
			}
			p=i,dis=0;
			while(p!=r){
				dis++;p=fr[p];
				if(dis>=x&&!vis[p]){
					rk++;
				}
			}
			if(lk<rk){
				int p=i,dis=0;
				while(p!=l){
					dis++;p=fl[p];
					if(dis>=x&&!vis[p]){
						nk++;vis[p]=1;
					}
				}
			}
			else{
				int p=i,dis=0;
				while(p!=r){
					dis++;p=fr[p];
					if(dis>=x&&!vis[p]){
						nk++;vis[p]=1;
					}
				}
			}
			flag=0;
		}
	}
//	cout<<nk<<" "<<k<<'\n';
	if(flag)return 1;
	return nk<=k;
}
void solve(){
	cin>>n>>k;
	
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	int l=1,r=n-1,ans=n-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)e[i].clear();
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
}