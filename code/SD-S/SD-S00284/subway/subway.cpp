// PLEASE GIVE ME 100 SCORE 
// O(n^3+q*d^2+m*d^2)复杂度，瓶颈在m*d^2。 
// 希望能用O2卡过。
// 祈求通过。
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
// PLEASE GIVE ME 100 SCORE
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\r'||ch=='\n') ch=getchar();
	if(ch=='-') ch=getchar(),sgn=1;
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(ll x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int M=5e5+10;
const int N=5e2+10;
const int D=25;
const ll INF=1e18;

int w[M];
struct Subway{
	int k;
	vector<int> a,t;
}s[N];
ll f[N][N];
vector<pair<int,int> > thr[M];
// idx+time

//void dfs(int u,int timer,int to) {
//	vis[u]=timer;
//	if(u==to) {
//		
//	}
//	for(auto x:thr[u]) {
//		for(int i=0;i<k;i++) {
//			int v=s[x].a[i],t=s[x].t[i];
//			if(vis[v]==timer) continue;
//			dfs(v,timer,to);
//		}
//	}
//}

void Solve() {
	int c=rint,n=rint,m=rint,d=rint,q=rint;
	for(int i=1;i<=m;i++) {
		w[i]=rint;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) {
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++) {
		s[i].k=rint; s[i].a.clear(),s[i].t.clear();
		for(int j=0;j<s[i].k;j++) {
			int x=rint,y=rint;
			thr[x].push_back({i,y});
			s[i].a.push_back(x),s[i].t.push_back(y);
		}
	}
	for(int i=1;i<=m;i++) {
		for(auto _x:thr[i]) {
			int x=_x.first,X=_x.second;
			for(auto _y:thr[i]) {
				int y=_y.first,Y=_y.second;
				if(x!=y) {
//					if(x>y) swap(x,y);
					f[x][y]=min(f[x][y],(ll)X+Y);
				}
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int u=rint,v=rint;
		if(u>v) swap(u,v);
		ll ans=INF;
		for(auto _x:thr[u]) {
			int x=_x.first,X=_x.second;
			for(auto _y:thr[v]) {
				int y=_y.first,Y=_y.second;
				if(x>y) swap(x,y);
//				if(i==2) cerr<<X<<' '<<Y;
				ans=min(f[x][y]+X+Y,ans);
			}
		}
		wint(ans+w[u]+w[v]); putchar('\n');
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Solve();
	return 0;
}

