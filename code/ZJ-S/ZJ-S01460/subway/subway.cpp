#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=6e5+5;
int c,n,m,d,q;
int a[maxn],vis[maxn],sum[maxn];
struct node{
	int v,w;
	bool operator <(const node &x)const{
		return v<x.v;
	}
};
struct node1{
	int v,w;
};
vector<node>g[maxn];
vector<int>g1[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			int k,x[2],y[2];
			cin>>k;
			if(k==2){
				cin>>x[0]>>y[0]>>x[1]>>y[1];
				g[x[0]].push_back({x[1],y[0]+y[1]});
				g[x[1]].push_back({x[0],y[0]+y[1]});
			}
			else{
				cin>>x[0]>>y[0];
			}
		}
//		while(q--){
//			int x,y;
//			
//		}
//		for(int i=1;i<=n;i++){
//			
//		}
	}
	else if(c>=12&&c<=19){
		int tmp=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				tmp=y;
				g1[x].push_back(i+m);
				g1[i+m].push_back(x);
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=n+m;i++){
				vis[i]=0;
			}
			queue<node1>q;
			q.push({x,0});
			vis[x]=1;
			while(!q.empty()){
				node1 u=q.front();
//				cout<<u.v<<" "<<u.w<<'\n';
				q.pop();
				if(u.v==y){
					cout<<u.w*tmp+a[x]+a[y]<<'\n';
					break;
				}
				for(auto v:g1[u.v]){
					if(vis[v]==0){
						q.push({v,u.w+1});
						vis[v]=1;
					}
				}
			}
		}
	}
	return 0;
}

