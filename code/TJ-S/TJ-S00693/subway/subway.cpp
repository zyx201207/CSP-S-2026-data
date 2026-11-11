#include<bits/stdc++.h>
using namespace std;
int w[50005],x[505],a[505][50005],t[505][50005];
struct node{
	int v,step;
};
int pq[5005][5005];
vector<node> p[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,v,s;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> x[i];
		for(int j=1;j<=x[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			for(int k=j+1;k<=x[i];k++){
				int jj=a[i][j],kk=a[i][k];
				/*if(pq[jj][kk]==0 || t[i][j]+t[i][k] < pq[jj][kk]){
					pq[jj][kk]=t[i][j]+t[i][k];
				}*/
				p[jj].push_back({kk,t[i][j]+t[i][k]});
			}
		}
		/*for(int j=1;j<=x[i];j++){
			for(int k=j+1;k<=x[i];k++){
				int jj=a[i][j],kk=a[i][k];
				if(pq[jj][kk]==0){
					continue;
				}
				p[jj].push_back({kk,pq[jj][kk]});
			}
		}*/
	}
	int st,en;
	/*for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			cout << p[i][j].v << ' ' << p[i][j].step << ',';
		}
		cout << endl;
	}*/
	while(q--){
		cin >> st >> en;
		int ans=w[st]+w[en];
		vector<int> dist(m,0);
		vector<bool> vis(m,0);
		queue<node> qq;
		qq.push({st,0});
		while(!qq.empty()){
			node e=qq.front();
			qq.pop();
			/*if(!vis[e.v]){
				vis[e.v]=1;
			}else{
				continue;
			}*/
			for(int i=1;i<=m;i++){
				if(i==st){
					continue;
				}
				for(int j=0;j<p[e.v].size();j++){
					int v=p[e.v][j].v,step=p[e.v][j].step;
					if(dist[v]==0 || dist[e.v]+step < dist[v]){
						//cout << v << ' ' << step << endl;
						dist[v]=dist[e.v]+step;
						qq.push({v,dist[v]});
					}
				}
			}
		}
		cout << ans+dist[en] << endl;
		/*for(int i=1;i<=m;i++){
			cout << dist[i] << ' ';
		}
		cout << endl;*/
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3


