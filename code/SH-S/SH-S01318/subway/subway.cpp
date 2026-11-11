#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5500],k[5500],t[5500][5050],dis[5050][5050];
vector <int> a[5500];
vector <int> st[5500];
void solve(){
	for(int i=0;i<=5000;i++){
		for(int j=0;j<=5000;j++){
			dis[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<a[i].size();j++){
			int u=a[i][j],v=a[i][j-1];
			dis[u][v]=dis[v][u]=t[i][u]+t[i][v];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			for(int J=0;J<st[i].size();J++){
			
			int line=st[i][j],line1=st[i][J];
			for(int k=0;k<a[line].size();k++){
				for(int p=0;p<a[line1].size();p++){
				
				int u=i,v=a[line][k],z=a[line1][p];
				dis[v][z]=dis[z][v]=min(dis[z][v],dis[v][u]+dis[u][z]+t[line][u]+t[line1][u]);
			}
			}
		}
	}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	if(c<=8){
		for(int i=1;i<=m;i++){
			 cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int A;
				cin>>A>>t[i][j];
				a[i].push_back(A);
				st[A].push_back(i);
			}
		}
		solve();
		while(q--){
			int x,y;
			cin>>x>>y;
			//freopen("subway.out","w",stdout);
			cout<<dis[x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
