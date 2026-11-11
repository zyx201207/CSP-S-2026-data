#include<bits\stdc++.h>
#define ll long long
using namespace std;
const int maxn=605;
const ll inf=1e15;
int c,n,m,d,q;
ll w[maxn],t[maxn],dis[maxn][maxn];
void init(){
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			if(i!=j){
				dis[i][j]=inf;
			}
		}
	}
}
void newdis(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(t[i]!=-1&&t[j]!=-1&&dis[i][j]>t[i]+t[j]){
				dis[i][j]=t[i]+t[j];
			}
		}
	}
}
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[i][j]>dis[i][k]+dis[j][k]){
					dis[i][j]=dis[i][k]+dis[j][k];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	init();
	int k,ai,ti;
	for(int i=1;i<=n;i++){
		cin>>k;
		memset(t,-1,sizeof t);
		while(k--){
			cin>>ai>>ti;
			t[ai]=ti;
		}
		newdis();
	}
	floyd();
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}