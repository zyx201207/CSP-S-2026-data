#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
const int NR=1e6+5;
int c,t,n,k,u[NR],v[NR];
int fa[25],lt,fl[25][25];
int find(int x) {
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x),y=find(y);
	if(x^y) {
		fa[x]=y;
		--lt;
	}
}
vector<int>E[NR];
void work() {
	cin>>n>>k;
	memset(fl,0x3f,sizeof(fl));
	rep(i,2,n) {
		cin>>u[i]>>v[i];
		fl[u[i]][v[i]]=fl[v[i]][u[i]]=1;
	}
	rep(i,1,n)fl[i][i]=0;
	rep(k,1,n)
	rep(i,1,n)
	rep(j,1,n)
	fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
	int ans=n+1;
	rep(S,0,(1<<n)-1) {
		lt=__builtin_popcount(S);
		rep(i,1,n) {
			fa[i]=i;
		}
		rep(i,2,n) {
			if((S>>(u[i]-1)&1)&&(S>>(v[i]-1)&1)) {
				merge(u[i],v[i]);
			}
		}
		if(lt<=2&&__builtin_popcount(S)==k) {
			int y=0;
			rep(i,1,n) {
				int d=n+1;
				rep(j,1,n) {
					if(S>>(j-1)&1) {
						d=min(d,fl[i][j]);
					}
				}
				y=max(y,d);
			}
			ans=min(ans,y);
		}
	}
	cout<<ans<<'\n';
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) 
		work();
	return 0;
}