#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=5e5+5;
const int inf=0x7f7f7f;
int c,n,m,d,q,w[maxm];
vector<pair<int,int>> lines[maxm];
int dis[15][15];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis,inf,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			lines[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<lines[i].size();j++){
			for(int k=0;k<lines[i].size();k++){
				pair<int,int> u=lines[i][j],v=lines[i][k];
				cerr<<u.first<<' '<<v.first<<'\n';
				if(dis[u.first][v.first]>u.second+v.second+w[u.first]+w[v.first] && u!=v){
					dis[u.first][v.first]=u.second+v.second+w[u.first]+w[v.first];
					dis[v.first][u.first]=u.second+v.second+w[u.first]+w[v.first];
				}
			}
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<m;j++){
			if(i!=j){
				for(int k=1;k<m;k++){
					if(j!=k){
						if(dis[i][j]>dis[i][k]+dis[k][j] && dis[i][k]+dis[k][j]>0){
							dis[i][j]=dis[i][k]+dis[k][j];
						}
					}
				}
			
			}
		}
		
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
