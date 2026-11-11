#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int to,w;
};
int c,n,m,d,qq,x[2005],y[2005],r;
int w[500005],k[505],a,dis[505][505],t;
queue<int>q[20005];
vector<node>G[505];
void bfs();
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	if(12<=c&&c<=19){
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a>>t;
				q[a].push(i);
				for(int k=1;k<=n;k++){
					dis[a][i]+=t;
					dis[i][a]+=t;
				}
			}
		}
		for(int i=1;i<=qq;i++){
			cin>>x[i]>>y[i];
		}
	}
	return 0;
}
