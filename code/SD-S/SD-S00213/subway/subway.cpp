#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[100005],x,y,tt,befa,befb,dis[8005][8005],vis[100005];
struct node{
	int subid,tim;
}a[505][100005];
vector<pair<int,int> > ve[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>tt;
		for(int j=1;j<=tt;j++){
			cin>>a[i][j].subid>>a[i][j].tim;
			if(j!=1){
				ve[befa].push_back(make_pair(a[i][j].subid,befb));
				ve[a[i][j].subid].push_back(make_pair(befa,befb));
			}
			befa=a[i][j].subid,befb=a[i][j].tim;
		}
	}
	for(int S=1;S<=n;S++){
		priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
//		memset(dis,0x3f,sizeof dis);//为了pianfen所关 
		memset(vis,0,sizeof vis);
		dis[S][0]=S;
		q.push({0,S});
		while(!q.empty()){
			pair<int,int> p=q.top();
			q.pop();
			if(vis[p.second]) continue;
			vis[p.second]=1;
			for(auto i:ve[p.second]){
				if(dis[S][i.second]>dis[S][p.second]+i.first){
					dis[S][i.second]=dis[S][p.second]+i.first;
					q.push({i.first,i.second});
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]+a[i][k].tim+a[j][k].tim);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
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
*/

