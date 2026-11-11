#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[505][505][2];
const int N=5e5+10;
int c,n,m,d,q,w[N];
struct node{
	int to,w;
}; 
void bfs(int x){
	queue<node> qu;
	qu.push({x,0});
	while(!qu.empty()){
		node u=qu.front();
		qu.pop();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==x||i==j||j==x) continue;
				if(dist[i][x][1]>u.w+dist[x][j][1]){
					dist[i][x][1]=u.w+dist[x][j][1];
					qu.push({j,dist[i][x][1]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dist[i][i][0]=w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int pos,w; cin>>pos>>w;
			for(int k=1;k<=m;k++){
				if(k!=pos){
					dist[k][pos][1]=dist[pos][k][1]=w;
				}
			}
		}	
	}
	while(q--){
		int l,r; cin>>l>>r;
		bfs(l);
		cout<<dist[l][r][1]+dist[l][l][0]+dist[r][r][0]<<"\n";
	}
	return 0;	
}
