#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;

inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}


int n,m,d,q;
int w[M];


pair<int,int> s[M][25];
int idx[M];
long long dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(dis,0x3f,sizeof dis);
	
	read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(register int i=1;i<=m;++i)w[i]=read();
	for(register int i=1;i<=n;++i){
		int k,a,t;
		k=read();
		for(register int j=1;j<=k;++j){
			a=read(); t=read();
			s[a][++idx[a]]=make_pair(i,t);
		}
		dis[i][i]=0;
	}
	for(register int i=1;i<=m;++i){
		for(register int j=1;j<=idx[i];++j){
			for(register int l=1;l<=idx[i];++l){
				if(j!=l){
					dis[s[i][j].first][s[i][l].first] = min(dis[s[i][j].first][s[i][l].first], 1ll*s[i][j].second+s[i][l].second);
				}
			}
		}
	}
	for(register int k=1;k<=n;++k){
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--){
		int x,y;
		x=read(); y=read();
		register long long res=5e18;
		for(register int j=1;j<=idx[x];++j){
			for(register int k=1;k<=idx[y];++k){
				res=min(res,dis[s[x][j].first][s[y][k].first]+s[x][j].second+s[y][k].second);
			}
		}
		printf("%lld\n",res+w[x]+w[y]);
	}
	
	return 0;
}
