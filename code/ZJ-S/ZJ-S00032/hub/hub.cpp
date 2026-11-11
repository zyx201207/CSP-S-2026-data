#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m,fl[1000009];
vector<int> u[1000009];
int st[1000009],tp;
struct n1{
	int x,y;
}bi[1000009];
int ma,dep[1000009],mad,f[1000009],dma[1000009];
int sum=0;
inline void dfs1(int x,int fa){
	fl[x]=1;dep[x]=dep[fa]+1;f[x]=fa;
	if(ma<dep[x]) ma=dep[x],mad=x;
	for(int y:u[x]){
		if(y==fa) continue;
		dfs1(y,x);
	}
}
inline void dfs2(int x,int fa,int mid){
	dep[x]=dep[fa]+1;dma[x]=dep[x];
	for(int y:u[x]){
		if(y==fa) continue;dfs2(y,x,mid);
		dma[x]=max(dma[x],dma[y]);
	}
	if(dma[x]-dep[x]>=mid) sum++;
}
inline pair<int,int> find_root(int x){
	ma=-1,mad=-1;dfs1(x,0);
	int xl=mad;ma=mad=-1;dfs1(xl,0);
	int xr=mad;tp=0;
	st[++tp]=xr;
	while(xr!=xl) xr=f[xr],st[++tp]=xr;
	return make_pair(st[(tp+1)/2],tp-1);
}
inline int que(int x,int mid){
	pair<int,int> k=find_root(x);
	if(mid>=(k.se+1)/2) return 1;
	sum=0;dfs2(k.fi,0,mid);
//	cout<<k.fi<<'\n';
	return sum;
}
inline bool check(int mid){
	for(int i=0;i<=n;i++) fl[i]=0;
	int num=0;
	for(int i=1;i<=n;i++){
		if(fl[i]==0){
			num+=que(i,mid);
		}
	}
	if(num<=m) return 1;
	return 0;
	return num;
}
mt19937 rn(time(0));
inline void solve(){
	cin>>n>>m;
	if(n<=4000){
		for(int i=1;i<n;i++){
			cin>>bi[i].x>>bi[i].y;
		}
		int ans=n;
		for(int i=0;i<n;i++){
			for(int j=1;j<=n;j++) u[j].clear();
			for(int j=1;j<n;j++){
				if(i==j) continue;u[bi[j].x].push_back(bi[j].y),u[bi[j].y].push_back(bi[j].x);
			}
			if(n==m) ans=0;
			else{
				int l=1,r=n;
				while(l<r){
					int mid=l+(r-l)/2;
					if(check(mid)) r=mid;
					else l=mid+1;
				}
				ans=min(ans,l);
			}
		}
		cout<<ans<<'\n';
	}
	else{
		int ci;
		if(n<=100000) ci=20;
		else ci=8;
		for(int i=1;i<n;i++){
			cin>>bi[i].x>>bi[i].y;
		}
		int ans=n;
		while(ci--){
			int i=rn()%n+1;
			for(int j=1;j<=n;j++) u[j].clear();
			for(int j=1;j<n;j++){
				if(i==j) continue;u[bi[j].x].push_back(bi[j].y),u[bi[j].y].push_back(bi[j].x);
			}
			if(n==m) ans=0;
			else{
				int l=1,r=n;
				while(l<r){
					int mid=l+(r-l)/2;
					if(check(mid)) r=mid;
					else l=mid+1;
				}
				ans=min(ans,l);
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,_;cin>>c>>_;
	while(_--) solve();
	return 0;
}