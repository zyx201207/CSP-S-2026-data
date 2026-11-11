#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int w,id;
};
vector<node> g[500010];
int w[500010];
int k[510];
int f[510][510];
int c,n,m,d,q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		f[i][i]=0;
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,i});
		}
	}
//	cout<<f[1][1]<<'\n';
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].size();j++)
			for(int k=j+1;k<g[i].size();k++){
				f[g[i][k].id][g[i][j].id]=g[i][k].w+g[i][j].w;
				f[g[i][j].id][g[i][k].id]=g[i][k].w+g[i][j].w;
			}
//	cout<<f[1][1]<<'\n';
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					f[j][i]=f[i][k]+f[k][j];
				}
//	cout<<f[1][1]<<'\n';
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=0x3f3f3f;
		for(int i=0;i<g[x].size();i++)
			for(int j=0;j<g[y].size();j++)
				minn=min(minn,f[g[x][i].id][g[y][j].id]+g[x][i].w+g[y][j].w);//,cout<<f[g[x][i].id][g[y][j].id]<<' '
		cout<<minn+w[x]+w[y]<<'\n';
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
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
