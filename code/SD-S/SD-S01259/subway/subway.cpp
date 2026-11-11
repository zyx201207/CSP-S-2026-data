#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
LL mi_n(LL x,LL y){
	return (x<y?x:y);
}
int w[500010];
//int ks[510];
vector<pii> g[500103];
LL gg[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
//		ks[i]=k;
		for(int j=1,x,y;j<=k;j++){
//			cin>>a[i][j].fi>>a[i][j].se;
			cin>>x>>y;
			g[x].push_back({m+i,y});
//			g[m+i].push_back({x,y});
//			g[a[i][j].fi].push_back({m+i,a[i][j].se});
//			g[m+i].push_back({a[i][j].fi,a[i][j].se});
		}
	}
//	for(int i=1;i<=m;i++)sort(g[i].begin(),g[i].end());
	
	memset(gg,0x3f,sizeof gg);
	for(int i=1;i<=m;i++){
		for(pii u:g[i]){
			for(pii v:g[i]){
				if(u.fi==v.fi)continue;
				gg[u.fi-m][v.fi-m]=(gg[u.fi-m][v.fi-m]==0x3f3f3f3f3f3f3f3f?u.se*1ll+v.se:mi_n(gg[u.fi-m][v.fi-m],u.se*1ll+v.se));
			}
		}
	}
	for(int i=1;i<=n;i++)gg[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gg[i][j]=mi_n(gg[i][j],gg[i][k]+gg[k][j]);
			}
		}
	}
	int x,y;
	LL ans;
	while(q--){
		ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(pii u:g[x]){
			for(pii v:g[y]){
				ans=mi_n(ans,gg[u.fi-m][v.fi-m]+w[x]+w[y]+u.se+v.se);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
