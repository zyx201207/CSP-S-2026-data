#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=2e4+10;
int a[30],t[30],e[M][M],w[M],dis[M];
bool book[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++){
		e[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				e[a[j]][a[l]]=t[j]+t[l];
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		int u,mins=INT_MAX/2;
		for(int j=i+1;j<=m;j++){
			if(!book[j] && e[i][j]<mins){
				u=j;
				mins=e[i][j];
				cout<<i<<" "<<j<<" "<<e[i][j]<<"\n";
			}
		}
		book[u]=1;
		for(int j=u;j<=m;j++){
			if(e[i][u]+e[u][j]<e[i][j]){
				e[i][j]=e[i][u]+e[u][j];
				cout<<i<<" "<<j<<" "<<e[i][j]<<"\n";
			}
		}
	}
	*/
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=i;k<=j;k++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		if(x>y){
			swap(x,y);
		}
		ll s=w[x]+w[y];
		cout<<s+e[x][y]<<"\n";
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

32
17



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
