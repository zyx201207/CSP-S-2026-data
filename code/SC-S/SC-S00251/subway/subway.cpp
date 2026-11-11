#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500];
int a[500][500005];
int t[500][500005];
int vis[500][500];
//int x[100005],y[100005];
int main(){
	//freopen("subway.in","i",stdin);
	//freopen("subway.out","w",stdout);
	
	//c:测试点编号 n:地铁线路数 m:地铁站数 d:每个地铁站最多被几条线路经过 q:出行计划数
	int t,n,m,d,q;
	cin>>t>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				
			}
		}
	}
	return 0;
} 