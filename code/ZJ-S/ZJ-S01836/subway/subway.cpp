#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,p[500100],w[501][501];
struct L{
	long long To,val;
};
vector<L>ww[501000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int w,p;
			cin>>w>>p;
			ww[w].push_back({i,p});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)w[i][j]=1e13;
	for(int i=1;i<=m;i++)
		for(int j=0;j<ww[i].size();j++)
			for(int k=j+1;k<ww[i].size();k++)
				w[ww[i][j].To][ww[i][k].To]=min(w[ww[i][j].To][ww[i][k].To],w[ww[i][k].To][ww[i][j].To]=ww[i][k].val+ww[i][j].val);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k&&w[i][k]<1e13)
				for(int j=1;j<=n;j++)
					if(j!=k&&i!=j&&w[j][k]<1e13)
						w[i][j]=min(w[i][j],w[j][k]+w[i][k]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e13;;
		for(int j=0;j<ww[x].size();j++)
			for(int k=0;k<ww[y].size();k++)
				ans=min(ans,w[ww[x][j].To][ww[y][k].To]+ww[x][j].val+ww[y][k].val);
		cout<<ans+p[x]+p[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
