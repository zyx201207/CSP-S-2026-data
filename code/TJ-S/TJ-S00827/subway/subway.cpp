#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int v,w;
};
bool operator < (node x,node y){
	return x.w > y.w;
}
priority_queue <node> qq;
vector <node> g[N];
int dis[N];
int vis[N];
int drr[N];
int arr[N],brr[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>drr[i];
	}
	for(int i=1;i<=n;i++){
		int x; 
		cin >>x;
		for(int j=1;j<=x;j++){
			arr[j]=0,brr[j]=0;
			cin>>arr[j]>>brr[j];
		}
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				g[arr[j]].push_back({arr[k],brr[j]+brr[k]});
				g[arr[k]].push_back({arr[j],brr[j]+brr[k]});
			}
		}
	}
	while(q--){
		int a,b;
		cin >>a>>b;
		for(int i=1;i<=500000;i++){
			dis[i]=1e9;
			vis[i]=0;
		}
		qq.push({a,0});
		dis[a]=0;
		while(!qq.empty()){
			int v=qq.top().v;
			qq.pop();
			if(vis[v]){
				continue;
			}
			vis[v]=1;
			for(auto it:g[v]){
				int vv=it.v;
				int w=it.w;
				if(dis[v]+w<dis[vv]){
					dis[vv]=dis[v]+w;
					qq.push({vv,dis[vv]});
				}
			}
		}
		cout<<dis[b]+drr[a]+drr[b]<<"\n";
	}
	return 0;
}
