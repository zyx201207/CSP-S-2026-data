#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q;
int a[500005];
vector<pair<int,int> >b[500005];
int c[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int y,t;cin>>y>>t;
			b[y].push_back({i,t});
		}
	}
	memset(c,0x3f,sizeof c);
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				c[b[i][j].first][b[i][k].first]=min(c[b[i][j].first][b[i][k].first],b[i][j].second+b[i][k].second);
				c[b[i][k].first][b[i][j].first]=c[b[i][j].first][b[i][k].first];
			}
		}
	}
	for(int i=1;i<=n;i++)c[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<b[x].size();i++){
			for(int j=0;j<b[y].size();j++){
				ans=min(ans,c[b[x][i].first][b[y][j].first]+b[x][i].second+b[y][j].second);
			}
		}
		cout<<a[x]+a[y]+ans<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
