#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
typedef long long ll;
typedef pair<ll,ll> pll;
vector< vector<pll> > to;
vector< vector<ll> > a,t;
int w[500005];
int tosz[500005];
int c,n,m,d,q;
ll dis[501][501];
char ch;
int ri(){
	ch=gc();
	int ans=0;
	while(isspace(ch))ch=gc();
	while(isdigit(ch)){
		ans=ans*10+(ch^'0');
		ch=gc();
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	c=ri();
	n=ri();
	m=ri();
	d=ri();
	q=ri();
	for(int i=1;i<=m;++i){
		w[i]=ri();
	}
	a.resize(n+1);
	t.resize(n+1);
	to.resize(m+1);
	for(int i=1;i<=n;++i){
		int k;
		k=ri();
		a[i].resize(k);
		t[i].resize(k);
		for(int j=0;j<k;++j){
			a[i][j]=ri();
			t[i][j]=ri();
			to[a[i][j]].push_back({i,t[i][j]});
			++tosz[a[i][j]];
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int tmp=tosz[i];
		for(int j=0;j<tmp;++j){
			for(int k=0;k<j;k++){
				int to1=to[i][j].first,dis1=to[i][j].second;
				int to2=to[i][k].first,dis2=to[i][k].second;
				dis[to1][to2]=dis[to2][to1]=dis1+dis2;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	int x,y;
	while(q--){
		x=ri();
		y=ri();
		ll ans=0x3f3f3f3f3f3f3f3f;
		int s1=tosz[x],s2=tosz[y];
		for(int i=0;i<s1;++i){
			for(int j=0;j<s2;++j){
				//cout<<to[x][i].first<<" "<<to[y][j].first<<" "<<dis[to[x][i].first][to[y][j].first]<<"\n";
				register ll tmp=to[x][i].second+to[y][j].second+dis[to[x][i].first][to[y][j].first];
				if(tmp<ans)ans=tmp;
			}
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
//miku miku!
