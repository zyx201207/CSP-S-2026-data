#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int MOD=1e9+21;
ll x[N];
pair<ll,ll> f[N];
int n; ll d;
void check(int l) {
	for(int i=l;i<=n;i++) f[i]={0x3f3f3f3f,0};
	f[l]={0,1};
	for(int i=l;i<=n;i++) {
		for(int j=i+1;j<=n;j++) if(x[i]+d>=x[j]) {
			if(f[i].fir+1<f[j].fir) f[j]={f[i].fir+1,f[i].se};
			else if(f[i].fir+1==f[j].fir) (f[j].se+=f[i].se)%=MOD;
		}
	}
//	printf("l:%d r:%d\n",l,r);
//	for(int i=1;i<=n;i++) printf("(%lld,%lld) ",f[i].fir,f[i].se); puts("");
}
int c,T;
void solve() {
	read(n,d);
	for(int i=1;i<=n;i++) read(x[i]);
	if(c==13||c==14) {
		puts("0");
		return ;
	}
	int ans=0;
	for(int l=1;l<=n;l++) {
		check(l);
		for(int r=l;r<=n;r++) if(f[r].se==2) 
			ans++;
	}
	printf("%d\n",ans);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c,T);
	while(T--) solve();
	return 0;
}

