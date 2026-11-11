#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
struct path{
	int a,t;
}p[25][50001],T[1000][1000];;
int x,y;
int k[25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>p[i][j].a;
			cin>>p[i][j].t;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			T[p[i][j].a][p[i-1][j].a=w[p[i][j].a]+w[p[i-1][j].a]+p[i][j].t+p[i-1][j].t;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<T[x][y]<<endl;
	}
	return 0;
} 
