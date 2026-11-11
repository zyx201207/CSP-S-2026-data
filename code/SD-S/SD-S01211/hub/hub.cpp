#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int c,T,n,k;
vector<int> vec[N];
int u[N],v[N],vis[N],f[N],ans,dis[N],dep[N],tmp;
void getdep(int x,int fa){
	dep[x]=dep[fa]+1;dis[x]=0;vis[x]=1;
	for(int i:vec[x]){
		if(i==fa) continue;
		getdep(i,x);dis[x]=max(dis[x],dis[i]+1);
	}
}
void getdis(int x,int fa,int fr){
	dis[x]=fr;vis[x]=1;
	int ma=fr,cma=0;
	for(int i:vec[x]){
		if(i==fa) continue;
		if(dep[i]+1>ma) {
			cma=ma;ma=dis[i]+1;
		}else cma=max(cma,dis[i]+1);
	}
	for(int i:vec[x]){
		if(i==fa) continue;
		getdis(i,x,(dis[i]+1==ma?cma+1:ma+1));
	}
}
void dfs(int x,int fa,int d){
	vis[x]=1;f[x]=1;
	for(int i:vec[x]){
		if(i==fa) continue;
		dfs(i,x,d);
		if(dep[i]>=d) f[x]+=f[i];
	}
	if(dis[x]<=d) {
		tmp=min(tmp,f[x]);
	}
}
bool check(int x){
	for(int i=1;i<=n;i++) vis[i]=0;int s=0;
//	cout<<"checking "<<x<<'\n';
//	for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			tmp=1e9;
			dfs(i,i,x); s+=tmp;
		}
	}
	return s<=k;
}
void solve(){
	for(int i=1;i<=n;i++) vis[i]=dis[i]=dep[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) getdep(i,i);
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) dep[i]=dis[i];
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			getdis(i,i,0);
		}
	} 
//	for(int i=1;i<=n;i++) cout<<dep[i]<<' '<<dis[i]<<'\n';
	int l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	ans=min(ans,l);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ans=1e9;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++) vec[i].clear();
			for(int j=1;j<n;j++){
				if(i!=j) {
					vec[u[j]].push_back(v[j]);
					vec[v[j]].push_back(u[j]);
				}
			}
			solve();
		}	
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
