#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
//#define int long long 
int ans,c,n,m,d,q,w[2*N],x,y,k[N],a[N][N],t[N][N],maxn,best[N]; 
void dfs(int x,int dis){
	if(best[x]<dis)return;
	best[x]=dis;
	if(x==y){
		ans=dis;
		return;
	}
	for(int i=1;i<=n;i++){
		int st=0;
		for(int j=1;j<=k[i];j++){
			st=j;
			if(a[i][j]==x)break;
		}
		for(int j=st;j<=k[i];j++){
			//if(ii==i)
			dfs(j,dis+a[i][j]);
			//else  dfs(j,dis+a[i][j]+a[ii][j],i);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		cin>>x>>y;
		dfs(x,0);
		cout<<(ans+w[x]+w[y])*2+7<<'\n';
	}
	return 0;
} 
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
/*
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
1 3
 1 2
 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3

*/


