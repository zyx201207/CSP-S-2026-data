#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e18;
int c,t,n,k,root,dis[N],dis_min,flag,mark[N];
vector<int> g[N];
vector<int> qu;
void get_root(int u,int pre){
	for(int v:g[u]){
		if(v==pre) continue;
		get_root(v,u);
		dis[u]=max(dis[v]+1,dis[u]);
	}
}
bool check1(int d){
	return rand()%2;
}
//void dfs(int x,int d){
//	if(x==k){
//		if(check1(d)) flag=1;
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!mark[i]){
//			mark[i]=1;
//			qu.push_back(i);
//			dfs(x+1,d);
//			qu.pop_back();
//			mark[i]=0;
//		}
//	}
//}
bool check(int d){
	for(int i=1;i<=10;i++) flag+=rand()%2;
	if(flag>5) return true;
	return false;
}
void get_ans(){
	int l=0,r=n,res;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			res=mid;
		}
		else l=mid+1;
	}
	cout<<res<<"\n";
}
void work(){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dis_min=INF;
		for(int i=1;i<=n;i++){
			memset(dis,0,sizeof(dis));
			get_root(i,0);
			if(dis[i]<dis_min) root=i,dis_min=dis[i];
		} 
//		cout<<root<<"\n";
		get_ans();
	}
}
signed main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	work();
	return 0;
}
//aaaaaa가가가가