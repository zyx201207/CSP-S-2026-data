#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;

namespace IO{
	#define gc getchar_unlocked()

	template<typename T>
	void read(T &x){
		char c;
		int sgn=1;
		while(c=gc,c<'0'||c>'9')if(c=='-')sgn=-1;
		x=c-'0';
		while(c=gc,c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0';
		x*=sgn;
	}

	template<typename T>
	void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x/10)print(x/10);
		putchar(x%10+'0');
	}

	#undef gc
}
using IO::read;
using IO::print;

int c,n,m,d,q;
int w[N];

vector<pair<int,ll> > p[N];
ll dis[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1;i<=n;i++){
		int k,a,v;ll t,T;
		read(k);
		for(int j=1;j<=k;j++){
			read(a);read(t);
			for(auto pir:p[a]){
				v=pir.first,T=pir.second;
				dis[v][i]=dis[i][v]=min(dis[v][i],t+T);
			}
			p[a].push_back(make_pair(i,t));
		}
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]!=inf&&dis[k][j]!=inf)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int u,v;ll Tx,Ty;
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto pirx:p[x]){
			u=pirx.first,Tx=pirx.second;
			for(auto piry:p[y]){
				v=piry.first,Ty=piry.second;
				if(dis[u][v]!=inf)ans=min(ans,dis[u][v]+Tx+Ty);
			}
		}
		print(ans+w[x]+w[y]);putchar('\n');
	}
	return 0;
}