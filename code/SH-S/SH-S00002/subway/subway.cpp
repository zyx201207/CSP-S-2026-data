#include<bits/stdc++.h>
using namespace std;
struct Tree{
	int to,w;
};
vector<Tree>tree[20010];
int c,n,m,d,q,w[20010],rai[100010][2];
int djstl(int x,int y){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	bool vis[20010];
	int dist[20010];
	for(int i=1;i<=m;i++){
		vis[i]=0;
		dist[i]=1000000010;
	}
	dist[x]=0;
	q.push({dist[x],x});
	while(q.size()){
		int f=q.top().first,s=q.top().second;
		q.pop();
		if(vis[s])continue;
		vis[s]=1;
		for(int i=0;i<tree[s].size();i++){
//			cout<<s<<' '<<tree[s][i].to<<endl;
			if(dist[tree[s][i].to]>f+tree[s][i].w){
				dist[tree[s][i].to]=f+tree[s][i].w;
//				cout<<tree[s][i].to<<' '<<dist[tree[s][i].to]<<endl;
				q.push({dist[tree[s][i].to],tree[s][i].to});
			}
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>rai[j][0]>>rai[j][1];
			for(int l=j-1;l>=1;l--){
				tree[rai[j][0]].push_back({rai[l][0],rai[j][1]+rai[l][1]});
				tree[rai[l][0]].push_back({rai[j][0],rai[j][1]+rai[l][1]});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++)cout<<to[i][j]<<' ';
//		cout<<endl;
//	}
	vector<int>needprint;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		needprint.push_back(w[x]+w[y]+djstl(x,y));
	}
	for(int i=1;i<=q;i++)cout<<needprint[i-1]<<endl;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
