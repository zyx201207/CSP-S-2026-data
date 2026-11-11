#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct node{
	int i,t;
}a[505][505];
int w[505];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j)dis[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].i>>a[i][j].t;
		}
		for(int l=1;l<=k;l++){
			for(int r=1;r<=k;r++){
				dis[a[i][l].i][a[i][r].i]=min(dis[a[i][l].i][a[i][r].i],a[i][r].t+a[i][l].t);
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
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]+w[l]+w[r]<<"\n";
	}
}
