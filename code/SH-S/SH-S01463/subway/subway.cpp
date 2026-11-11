#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e15+10;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
vector<int> xianlu[N]; //站点-线路数量(d<=20,k5e5) 
struct node{
	int a; //线路的目的地 
	int t;  //线路厅-站时间 
};
vector<node> G[510];
int dis[510][510]; //i到j线最小换成时间 
bool vis[510]; 

void sakura(){
	queue<int> q;
	q.push(1); vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		for(auto i:G[u]){
			
		}
	} 
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,b;j<=k;j++){
			cin>>a>>b;
			node len; len.a=a; len.t=b; 
			G[i].push_back(len);
			xianlu[a].push_back(i);
		}
	}
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++) dis[i][j]=maxn;
	for(int i=1;i<=m;i++) {
		
	}
	return 0;
}
