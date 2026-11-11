#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define int long long
const int N=2e6+5;
int T,n,d,ans;
int x[N],dis[N],dep[N];
vector<int> e[N];
void dfs(int now,int pre){
	for(int i=0;i<e[now].size();i++){
		int v=e[now][i];
		if(v==pre) continue;
		if(dep[v]==0){
			dep[v]=dep[now]+1;
			dis[v]=dis[now];
			if(dis[v]==2) ans++;
		}
		else{
			if(dep[v]<=dep[now]) continue;
			if(dep[v]==dep[now]+1){
				dis[v]++;
				if(dis[v]==2) ans++;
				if(dis[v]==3) ans--;
			}
			else{
				if(dis[v]==2) ans--;
				dis[v]=dis[now];
				if(dis[v]==2) ans++;
				dep[v]=dep[now]+1;
			}
		}
		dfs(v,now);
	}
}
void solve(){
	cin>>n>>d;
	cin>>x[1];
	int k=1;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=2;i<=n;i++){
		cin>>x[i];
		while(x[i]-x[k]>d){
			k++;
		}
		for(int j=k;j<i;j++){
			e[j].push_back(i);
			e[i].push_back(j);
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		memset(dep,0,sizeof(dep));
		memset(dis,0,sizeof(dis));
		dis[i]=1;
		dep[i]=1;
		dfs(i,0);
//		for(int j=1;j<=n;j++){
//			cout<<dep[j]<<' ';
//		}
//		cout<<'\n';
//		for(int j=1;j<=n;j++){
//			cout<<dis[j]<<' ';
//		}
//		cout<<'\n';
	}
	cout<<ans/2<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		solve();
	}
	return 0;
}
