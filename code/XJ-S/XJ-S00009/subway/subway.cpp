#include<bits/stdc++.h>
using namespace std;
const int p = 5e4+5;
int id,n,m,r,q2,w[p],a[501][p],t[501][p],b[p],c[p],dist[p];
vector<int>d[p];
queue<int>q;
void bfs(int s,int s2){
	memset(b,0,sizeof b);
	memset(dist,127,sizeof dist);
	q.push(s);
	b[s] = 1;
	dist[s] = w[s];
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto y : d[x]){
			if(b[y])continue;
			dist[y] = min(dist[y],dist[x]+t[c[x]][x]+t[c[x]][y]);
			b[y] = 1;
			q.push(y);
		}
	}
	dist[s2] += w[s2];
	cout << dist[s2] << '\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> id >> n >> m >> r >> q2;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j];cin >> t[i][a[i][j]];
			c[a[i][j]] = i;
			if(j != 1){
				d[a[i][j]].push_back(a[i][j-1]);
				d[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	while(q2--){
		int l,r;
		cin >> l >> r;
		bfs(l,r);
	}
	return 0;
}
