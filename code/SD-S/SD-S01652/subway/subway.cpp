#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q;
int w[M],k[N],a[N][N],t[N][N];
vector<int> ve[M];
priority_queue<int,vector<int>,greater<int> >qu; 
int vis[N],dist[N];
void dijkstra(int s,int e){
	qu.push(s);
	vis[s]=1;
	dist[s]=0;
	while(!qu.empty()){
		int f=qu.top();
		qu.pop();
		if(vis[f]) continue;
		if(f==e) return ;
		for(int i=0;i<ve[f].size();i++){
			
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k[i];j++){
			ve[a[i][j]].push_back(a[i][j-1]);
			ve[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
	}
	return 0;
}
//Oct31==Dec25?
