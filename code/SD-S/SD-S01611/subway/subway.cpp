#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=5e5+50;
vector<PII>xian[N];
ll dis[505][505];
ll w[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c,n,m,d,q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++) {
		int k;
		read(k);
		for(int j=1;j<=k;j++) {
			int a,t;
			read(a,t);
			xian[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(PII t1:xian[i]) 
			for(PII t2:xian[i]) 
				dis[t1.fir][t2.fir]=min(dis[t1.fir][t2.fir],t1.se+t2.se);
	}
	for(int k=1;k<=n;k++) 
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) 
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++) {
		int x,y;
		read(x,y);
		ll ans=4e18;
		for(PII t1:xian[x])
			for(PII t2:xian[y]) {
				ll t=w[x]+w[y]+t1.se+t2.se+dis[t1.fir][t2.fir];
				ans=min(ans,t);
			} 
		printf("%lld\n",ans);
	}
	return 0;
}
