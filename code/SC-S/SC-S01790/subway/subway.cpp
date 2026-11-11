#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
vector<pair<int,int > >point[M];//first:subway,second:weight
int cost[N][N],dis[N][N],vis[N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=1e9;
			if(i==j){
				cost[i][j]=0;
			}
		}
	}
	int k,u,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>u>>t;
			point[u].push_back(make_pair(i,t));
		}
	}for(int i=1;i<=m;i++){
		for(auto j:point[i]){
			for(auto l:point[i]){
				if(l.first!=j.first){
					cost[j.first][l.first]=cost[l.first][j.first]=min(cost[l.first][j.first],l.second+j.second);
				}
			}
		}
	}/*part what need to delete
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<cost[i][j]<<" ";
		}
		cout<<"\n";
	}
	//part what need to delete*/ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(cost[i][j]+cost[i][l]<cost[j][l]){
					cost[j][l]=cost[l][j]=cost[i][j]+cost[i][l];
				}
			}
		}
	}
	
	int x,y;int mn=1e9;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		mn=1e9;
		for(auto j:point[x]){
			for(auto l:point[y]){
				mn=min(mn,w[x]+w[y]+cost[j.first][l.first]+l.second+j.second);
			}
		}
		cout<<mn<<"\n";
	}
} /*
5 5
1 2 4 8 9
*/