#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=510,M=500010;
int c,n,m,d,q,w[M],k[N],x,y,siz[M],dis[N][N];
vector<int>a[N],t[N];
vector<pair<int,int>>g[M];

inline void read(int&x){
	x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f^=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x=(f?-x:x);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,31,sizeof(dis));
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i)
		read(w[i]);
	for(int i=1;i<=n;++i){
		read(k[i]);
		for(int j=0;j<k[i];++j){
			int A,T;
			read(A),read(T);
			a[i].push_back(A);
			t[i].push_back(T);
			g[A].push_back({i,T});
		}
	}
	for(int i=1;i<=m;++i){
		siz[i]=g[i].size();
		for(int j=0;j<siz[i]-1;++j)
			for(int k=j+1;k<siz[i];++k){
				int u1=g[i][j].first,u2=g[i][k].first;
				int t1=g[i][j].second,t2=g[i][k].second;
				dis[u1][u2]=min(dis[u1][u2],t1+t2);
				dis[u2][u1]=dis[u1][u2];
			}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		read(x),read(y);
		int ans=LONG_LONG_MAX;
		for(int i=0;i<siz[x];++i)
			for(int j=0;j<siz[y];++j)
				ans=min(ans,g[x][i].second+g[y][j].second+dis[g[x][i].first][g[y][j].first]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}