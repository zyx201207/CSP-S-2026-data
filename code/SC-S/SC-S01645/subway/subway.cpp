#include<bits/stdc++.h>
using namespace std;
const int M=1009;
int m,n,c,d,q,w[M],vis[M];
int t[M][M],road[M][M];
void bfs(int x){
	queue< pair<int,int> > q;
	q.push({x,x});
	vis[x]=t[x][x];
	while(q.size()!=0){
		int xx=q.front().second;
		int uu=q.front().first;
		q.pop();
		for(int i=1;i<=m;i++){
			if(vis[i]==0&&t[xx][i]!=0){
				q.push({xx,i});
				if(road[xx][i]!=road[uu][xx]){
					vis[i]=t[xx][xx]+t[xx][i]+vis[xx];
				}
				else{
					vis[i]=vis[xx]+t[xx][i];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> a;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a.push_back(x);
			t[i][x]=y;
			t[x][i]=y;
		}
		for(int j=0;j<k;j++){
			for(int z=0;z<k;z++){
				road[a[j]][a[z]]=i;
				road[a[z]][a[j]]=i;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		bfs(x);
		cout<<vis[y]+w[x]+w[y]<<endl;
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
	}
	return 0;
}