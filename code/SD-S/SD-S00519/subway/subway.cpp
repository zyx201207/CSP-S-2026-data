#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,q,a[M][30],p[M];
ll w[M],d[N][N],t[M][30];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,_d;
	cin>>c>>n>>m>>_d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int _k;
		cin>>_k;
		for(int j=1;j<=_k;j++){
			int x;ll y;
			cin>>x>>y;
			a[x][++p[x]]=i;
			t[x][p[x]]=y;
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p[i];j++){
			for(int k=1;k<=p[i];k++){
				if(j==k) continue;
				int u=a[i][j],v=a[i][k];
				ll nw=t[i][j]+t[i][k];
				d[u][v]=min(d[u][v],nw);
				d[v][u]=min(d[v][u],nw);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=inf;
		for(int i=1;i<=p[x];i++){
			for(int j=1;j<=p[y];j++){
				int u=a[x][i],v=a[y][j];
				res=min(res,d[u][v]+t[x][i]+t[y][j]);
			}
		}
		cout<<res+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
#1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


#2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/
