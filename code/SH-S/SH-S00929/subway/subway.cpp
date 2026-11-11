#include <bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=5e5+5,MAXE=1e6+5;
const long long INF=1e13;
int c,n,m,d,q,cost[MAXM];
long long dis_floyd[505][505];
vector<pair<int,long long> > pr[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i) cin >> cost[i];
	

	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis_floyd[i][j]=INF;
		}
		dis_floyd[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		int k;
		cin >> k;
		for(int pp=1;pp<=k;++pp){
			int x,y;
			cin >> x >> y;
			pr[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;++i){
		for(auto k: pr[i]){
			for(auto l:pr[i]){
				dis_floyd[k.first][l.first]=min(dis_floyd[k.first][l.first],k.second+l.second);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis_floyd[i][j]>dis_floyd[i][k]+dis_floyd[k][j]){
					dis_floyd[i][j]=dis_floyd[i][k]+dis_floyd[k][j];
				}
			}
		}
	}

	for(int i=1;i<=q;++i){
		int x,y;
		cin >> x >> y;
		long long ans=1e13;
		for(auto k: pr[x]){
			for(auto l:pr[y]){
				ans=min(ans,dis_floyd[k.first][l.first]+k.second+l.second);
			}
		}
		cout << ans+cost[x]+cost[y] << endl;
	}
	
	return 0;
} 
