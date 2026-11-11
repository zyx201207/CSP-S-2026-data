#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=6e5+5;
const int M=25;
const int K=505;
const ll INF=0x3f3f3f3f3f3f3f3f;
int st,en;
int c,n,m,d,q;
int len[N];
ll ww[N],dis[K][K];
struct edge {
	int v;
	ll w;
} con[N][M];
void build(int id) {
	for(int i=1; i<=len[id]; i++)
		for(int j=i+1; j<=len[id]; j++) {
			edge u1=con[id][i],v1=con[id][j];
			int uu=u1.v,vv=v1.v;
			ll dd=u1.w+v1.w;
			dis[uu][vv]=min(dis[uu][vv],dd);
			dis[vv][uu]=min(dis[vv][uu],dd);
		}
}
void step1() {
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) dis[i][j]=min(dis[i][j],dis[j][i]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>ww[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) dis[i][j]=dis[j][i]=INF;
	for(int i=1,ll1; i<=n; i++) {
		cin>>ll1;
		for(int j=1,id; j<=ll1; j++) {
			ll val;
			cin>>id>>val;
			len[id]++;
			con[id][len[id]].v=i,con[id][len[id]].w=val;
		}
	}
	for(int i=1; i<=m; i++) build(i);
	step1();
	while(q--) {
		cin>>st>>en;
		ll ans=INF;
		for(int id1=1; id1<=len[st]; id1++) {
			for(int id2=1; id2<=len[en]; id2++) {
				ll add=con[st][id1].w+con[en][id2].w;
				int zh1=con[st][id1].v,zh2=con[en][id2].v; 
				add=add+dis[zh1][zh2];
				ans=min(ans,add);
			}
		}
		ans=ans+ww[st]+ww[en];
		cout<<ans<<endl;
	}
	return 0;
}
