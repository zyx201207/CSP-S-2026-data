#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int c,n,m,d,q;
int dis[5005][5005];
int val[N];
int x[N],w[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=m; i++)dis[i][i]=0;
	for(int i=1; i<=m; i++) {
		cin>>val[i];
	}
	for(int i=1; i<=n; i++) {
		int t;
		cin>>t;
		for(int j=1; j<=t; j++)cin>>x[j]>>w[j];
		for(int l=1; l<=t; l++){
			for(int r=1; r<=t; r++){
				if(l==r)continue;
				dis[x[l]][x[r]]=w[l]+w[r];
			}
		}
	}
	for(int k=1; k<=m; k++){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=m; j++){
				if(i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}	
	}
//	cout<<endl;
//	for(int i=1; i<=m; i++){
//		for(int j=1; j<=m; j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<val[l]+val[r]+dis[l][r]<<endl;
	}
	return 0;
}
//神兽保佑，代码无bug!!!
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/


