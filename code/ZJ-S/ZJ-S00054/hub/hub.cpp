#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=4e18;
int c,T,n,k,d[N],vis[N];
vector<int>e[N];
queue<int>q;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		//cout<<1;
		cin>>n>>k;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		vis[1]=1;
		d[1]=0;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				if(vis[v]==1) continue;
				d[v]=d[u]+1;
				q.push(v);
				vis[v]=1;
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,d[i]);
		}
		cout<<mx/2<<'\n';
	}
	return 0;
}
