#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<21],*p1,*p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin),p1 == p2) ? 0 : *p1++)
template <typename T>
inline void read(T& x){
	x = 0;
	int f = 1;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
const int INF = 1e18 + 7;
int c,n,m,d,q;
int w[500010];
typedef pair<int,int> pii;
vector<pii>vc[500010]; 
int f[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i = 1; i <= m; i++) read(w[i]);
	for(int i = 1,k; i <= n; i++){
		read(k);
		for(int j = 1,x,y; j <= k; j++){
			read(x),read(y);
			vc[x].push_back({i,y});
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = INF;
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int o = 1; o <= m; o++){
		for(auto I : vc[o]){
			for(auto J : vc[o]){
				int i = I.first,j = J.first,val = I.second + J.second;
				f[i][j] = min(f[i][j],val);
				f[j][i] = min(f[j][i],val);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	int X,Y;
	while(q--){
		read(X),read(Y);
		int ans = INF;
		for(auto I : vc[X]){
			for(auto J : vc[Y]){
				int i = I.first,j = J.first,val = I.second + J.second;
				ans = min(ans,val + f[i][j]);
			}
		}
		ans += w[X] + w[Y];
		printf("%lld\n",ans);
	}
	return 0;
} 
