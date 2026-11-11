#include <bits/stdc++.h>
using namespace std;
#define drintf(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
int rd(){
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const int maxm=5e5+10;
const int maxn=500+10;
const int maxd=20+2;
const ll INF=1e18;
int c,n,m,d,q;
ll w[maxm];
pair<int,int> st2li[maxm][maxd];
int s2lcnt[maxm];
ll e[maxn][maxn];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();
	n=rd();
	m=rd();
	d=rd();
	q=rd();
	for(int i=1;i<=m;++i){
		w[i]=rd();
	}
	for(int i=1;i<=n;++i){
		int k;
		k=rd();
		for(int j=1;j<=k;++j){
			int p;
			ll t;
			p=rd();
			t=rd();
			++s2lcnt[p];
			st2li[p][s2lcnt[p]]={i,t};
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			e[i][j]=INF;
		}
		e[i][i]=0ll;
	}
	for(int i=1;i<=m;++i){
		int trr=s2lcnt[i];
		for(int j=1;j<=trr;++j){
			for(int k=j+1;k<=trr;++k){
				int u=st2li[i][j].first;
				int v=st2li[i][k].first;
				e[u][v]=min(e[u][v],(ll)st2li[i][j].second+st2li[i][k].second);
				e[v][u]=e[u][v];
			}
		}
	}	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(e[i][j]>e[i][k]+e[k][j]){
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		x=rd();
		y=rd();
		ll ans=INF;
		for(int i=1;i<=s2lcnt[x];++i){
			for(int j=1;j<=s2lcnt[y];++j){
				ans=min(ans,e[st2li[x][i].first][st2li[y][j].first]+(ll)st2li[x][i].second+st2li[y][j].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}


