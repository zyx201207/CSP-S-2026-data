#include<bits/stdc++.h>
using namespace std;
const int M=1005;
int c,n,m,d,q;
int dis[M][M],w[M],a[M],t[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	if(m<=1000){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[j]>>t[j];
			}
			for(int u=1;u<=k;u++){
				for(int v=u+1;v<=k;v++){
					dis[a[u]][a[v]]=t[u]+t[v];
					dis[a[v]][a[u]]=t[u]+t[v];
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<dis[l][r]+w[l]+w[r]<<"\n";
		}
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
