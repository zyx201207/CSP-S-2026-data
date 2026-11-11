#include<bits/stdc++.h>
#define ll long long
#define gc getchar
#define endl puts("");
#define int ll
using namespace std;
namespace linan05006_hxy{
	inline int read(){int s=0,w=1;char c=gc();while(c>'9'||c<'0'){if(c=='-')w=-1;c=gc();}while(c<='9'&&c>='0')s=(s<<3)+(s<<1)+c-'0',c=gc();return s*w;}
	inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
}
using namespace linan05006_hxy;
int const N=505,M=5e5+5;
int w[M],f[N][N];
struct node{
	int x,dis;
};
vector<node>subway[N],e[M];
inline void solve(){
	int c=read(),n=read(),m=read(),d=read(),_=read(),k,a,b;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			f[j][i]=f[i][j]=0x3f3f3f3f3f3f3f3f;//i<j
		}
		k=read();
		for(int j=1;j<=k;j++){
			a=read(),b=read();
			e[a].push_back({i,b});
			subway[i].push_back({a,b});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:e[i]){
			for(auto v:e[i]){
				a=u.x,b=v.x;
				if(a>b)swap(a,b);
				f[a][b]=f[b][a]=min(f[a][b],u.dis+v.dis);
			}
		}
	}
	for(k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(_--){
		a=read(),b=read(),k=0x3f3f3f3f3f3f3f3f;
		for(auto u:e[a]){
			for(auto v:e[b]){
				k=min(k,f[u.x][v.x]+u.dis+v.dis);
			}
		}
		write(k+w[a]+w[b]),endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	int _=1;
//	_=read();
	for(int i=1;i<=_;i++)solve();
	return 0;
}
