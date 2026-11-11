#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int t;
};
int c,n,m,d,q;
int w[500005],k[505];
int a[505][500005],t[505][500005];
vector<node> g[500005];
int main(){
	freopen("r","subway.in",stdin);
	freopen("w","subway.out",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			g[a[i][j]].push_back({i,t[i][j]});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		int flag=0;
		int i,j;
		for(i=0;i<g[x].size();i++){
			for(j=0;j<g[y].size();j++){
				if(g[x][i].id==g[y][j].id){
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		if(flag==1){
			sum+=g[x][i].t+g[y][j].t;
		}
		cout<<sum;
	}
	return 0;
}