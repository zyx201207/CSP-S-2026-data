#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[250005],a[505][500005],t[505][500005],v[505],vis[500005];
struct node{
	int v8,w;
};
vector<node> g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>v[i];
			for(int j=1;j<=v[i];j++){
				cin>>a[i][j]>>t[i][j];
				for(int k=1;k<j;k++){
					g[a[i][j]].push_back({a[i][k],t[i][j]+t[i][k]});
					g[a[i][k]].push_back({a[i][j],t[i][j]+t[i][k]});
				}
			}
		}
		int x,y;
		queue<int> q3;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			q3.push(x);
			vis[x]=1;
			while(!q3.empty()){
				int d=q3.front();
				q3.pop();
				for(auto vwe:g[d]){
					if(vis[vwe.v8]==0){
						
					}
				}
			}
		}
	return 0;
}
//lmy
