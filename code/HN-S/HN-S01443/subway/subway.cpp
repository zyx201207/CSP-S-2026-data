#include<bits/stdc++.h>
#define ll long long 
#define MAX 1152921504606846976
using namespace std;
int c,n,m,d,q;
int w[50001],a[501][50001],t[501][50001],k[501];
int x,y;
ll times;
ll path[2001][2001];
ll dis[2001][2001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			path[i][j]=dis[i][j]=MAX;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(l==j)path[a[i][l]][a[i][j]]=0;
				else{
					path[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
					dis[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				}
			}
		}
	}
	//n*k^2
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]>=dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	//m^3
	for(int i=1;i<=q;i++){
		times=0;
		cin>>x>>y;
		times+=w[x]+w[y];
		times+=dis[x][y];
		cout<<times<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
