#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e5+5;
int w[N],k[N],a[500][N],t[500][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//fijk=从i到j经k中转的最少时间 
	for(int i=1;i<=m;i++){
		cin>>w[i];//口到厅 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j];//线路经过 
			cin>>t[a[i][j]][i];//厅到台 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<"\n";
	}
	return 0;
}
