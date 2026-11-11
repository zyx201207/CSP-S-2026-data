#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
#define ll long long
#define N 505
#define M 500005
ll w[M];vector<ll>t[N];
int c,n,m,d,nQ;vector<int>a[N];
#define PII pair<int,int>
#define bel first
#define pos second
vector<PII>g[M];
ll f[N][N];
void solve(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<a[i].size();j++)
			g[a[i][j]].push_back(make_pair(i,j));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)f[i][j]=1e18;
	for(int i=1;i<=n;i++)
		for(int u=0;u<a[i].size();u++){
			int x=a[i][u];
			for(int k=0;k<g[x].size();k++){
				int j=g[x][k].bel;
				int v=g[x][k].pos;
				f[i][j]=min(f[i][j],t[i][u]+t[j][v]);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(nQ--){
		int S,T;
		scanf("%d%d",&S,&T);
		ll res=1e18;
		for(int u=0;u<g[S].size();u++)
			for(int v=0;v<g[T].size();v++){
				int i=g[S][u].bel;
				int j=g[T][v].bel;
				int p=g[S][u].pos;
				int q=g[T][v].pos;
				res=min(res,f[i][j]+t[i][p]+t[j][q]+w[S]+w[T]);
			}
		printf("%lld\n",res);
	}
}
int main(){
	file();
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&nQ);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		t[i].resize(k);
		for(int j=0;j<k;j++)scanf("%d%lld",&a[i][j],&t[i][j]);
	}
	solve();
	return 0;
}
