#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct sc{
	int u,tt;
};
vector<sc> g[N];
bool vis[N];
int mn=INT_MAX;
void dfs(int x,int y,int sum){
	if(x==y){
		mn=min(mn,sum);
	}
	for(auto it:g[x]){
		if(!vis[it.u]){
			vis[it.u]=1;
			dfs(it.u,y,sum+it.tt);
			vis[it.u]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>v>>u;
			g[v].push_back({u,1});
			g[u].push_back({v,1});
		}
		while(k--){
			int mx=INT_MIN,mxx1;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					vis[i]=1;
					dfs(i,j,0);
					if(mx<mn){
						mx=mn;
						mxx1=j;
					}
					mn=INT_MAX;
					vis[i]=0;
				}
			}
			for(auto it:g[mxx1]){
				for(auto itt:g[it.u]){
					if(itt.u==mxx1){itt.tt=0;break;}
				}
				it.tt=0;
			}
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				vis[i]=1;
				dfs(i,j,0);
				if(mx<mn){
					mx=mn;
				}
				mn=INT_MAX;
				vis[i]=0;
			}
		}
		cout<<mx<<"\n";
	}
	return 0;
}