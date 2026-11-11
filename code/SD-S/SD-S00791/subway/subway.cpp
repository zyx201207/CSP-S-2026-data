#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define pii pair<int,int>
#define fr first
#define se second
#define eb emplace_back
#define inf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
using namespace std;

const int MAXN=520,MAXM=5e5+10;

int n,m,d,q,w[MAXM];
ll dis[MAXN][MAXN];
vector<pii> Way[MAXM];

int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,a,t;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>t,Way[a].eb(i,t);
	}
	for(int i=1;i<=m;i++){
		int siz=Way[i].size();
		for(int j=0;j<siz;j++) for(int k=0;k<j;k++){
			dis[Way[i][j].fr][Way[i][k].fr]=min(dis[Way[i][j].fr][Way[i][k].fr],(ll)(Way[i][j].se+Way[i][k].se));
			dis[Way[i][k].fr][Way[i][j].fr]=min(dis[Way[i][k].fr][Way[i][j].fr],(ll)(Way[i][j].se+Way[i][k].se));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--){
		ll ans=inf;
		int x,y;
		cin>>x>>y;
		for(pii st:Way[x]) for(pii ed:Way[y]) ans=min(ans,dis[st.fr][ed.fr]+st.se+ed.se);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
