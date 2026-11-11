#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q,k[1000001],a[1000001],t[1000001],g[1001][1001],w[1000001],T,vis[1000001],dis[1000001];
vector<int> g2[1000001];
struct jo{
	int x,y;
};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			g[i][j]=1e16;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				if(m<=500) g[a[j]][a[z]]=t[j]+t[z],g[a[z]][a[j]]=t[z]+t[j];
				g2[a[j]].push_back(a[z]);
				g2[a[z]].push_back(a[j]);
				T=t[j];
			}
		}
	}
//	cout<<666;
	if(m<=500){
//		cout<<666;
		for(int i=1;i<=m;i++) g[i][i]=0;
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<g[x][y]+w[x]+w[y]<<"\n";
		}
	}
	else{
//		cout<<T<<"\n";
//		cout<<666;
		while(q--){
			for(int i=1;i<=m;i++) vis[i]=0,dis[i]=0;
			int x,y;
			cin>>x>>y;
//			cout<<x<<" "<<y<<"\n";
			queue<jo> q;
			q.push({x,0});
			vis[x]=1;
			while(q.size()){
				jo b=q.front();
				q.pop();
				if(b.x==y){
					cout<<b.y*T+w[x]+w[y]<<"\n";
					break;
				}
				for(int i:g2[b.x]){
					if(vis[i]) continue;
					vis[i]=1;
					q.push({i,b.y+1});
				}
			}
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
