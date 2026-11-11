#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mod ((LL)1e9+7)
#define inf ((LL)0x3f3f3f3f3f3f3f3f)
#define esp ((long double)1e-7)
#define len(x) ((LL)(x.size()))
inline LL mo(const LL x){return x-x/mod*mod;}
inline LL mo(const LL x,const LL p){return x-x/p*p;}
inline LL _mo(const LL x,const LL p){return mo(mo(x,p)+p,p);}
#define N ((LL)5e2+7)
#define M ((LL)5e5+7)
LL c,n,m,d,q,w[M],dis[N][N];
vector<PLL> v[M];
inline LL min(const LL x,const LL y){
	return (x<y?x:y);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(LL i=1;i<=m;++i){
		cin>>w[i];
	}
	for(LL i=1,k,t,a;i<=n;++i){
		dis[i][i]=0;
		cin>>k;
		while(k--){
			cin>>a>>t;
			v[a].push_back(mp(i,t));
		}
	}
	for(LL i=1;i<=m;++i){
		for(LL j=1;j<len(v[i]);++j){
			LL x1=v[i][j].first,d1=v[i][j].second;
			for(LL k=0;k<j;++k){
				dis[x1][v[i][k].first]=min(dis[x1][v[i][k].first],d1+v[i][k].second);
			}
		}
	}
	for(LL k=1;k<=n;++k){
		for(LL i=2;i<=n;++i){
			for(LL j=1;j<i;++j){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
			}
		}
	}
	while(q--){
		LL s,t,ans=inf;
		cin>>s>>t;
		for(auto x : v[s]){
			for(auto y : v[t]){
				ans=min(ans,dis[x.first][y.first]+x.second+y.second);
			}
		}
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
