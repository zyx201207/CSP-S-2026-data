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
int c,T,n,d;
int x[2000010],pre[2000010],nxt[2000010];
int id[2000010],sz[2000010],L[2000010],R[2000010],f[2000010],g[2000010]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(T);
	while(T--){
		read(n),read(d);
		for(int i = 1; i <= n; i++) read(x[i]),L[i] = R[i] = 0,id[i] = 0,sz[i] = 0;
		int lim = 1;
		for(int i = 1; i <= n; i++){
			while(x[i] - x[lim] > d) lim++;
			pre[i] = lim;
		}
		lim = n;
		for(int i = n; i >= 1; i--){
			while(x[lim] - x[i] > d) lim--;
			nxt[i] = lim;
		}
		for(int i = 1; i <= n; i++){
			if(nxt[i] != i && pre[nxt[i]] == i){
				R[i] = nxt[i];
				L[nxt[i]] = i;
			}
		}
		for(int i = n; i >= 1; i--){
			if(!R[i]) g[i] = 0;
			else{
				g[i] = g[R[i]];
				int xx = R[i];
				while(xx > i && pre[xx] == i) g[i]++,xx--;
			}
		}
		for(int i = 1; i <= n; i++){
			if(!L[i]) f[i] = 0;
			else{
				f[i] = f[L[i]];
				int xx = L[i];
				while(xx < i && nxt[xx] == i) f[i]++,xx++;
			}
		}
//		for(int i = 1; i <= n; i++) printf("%lld %lld %lld %lld\n",pre[i],nxt[i],f[i],g[i]);
		int ans = 0;
		for(int p = 2; p < n - 1; p++){
			if(pre[p] == p || nxt[p + 1] == p + 1) continue;
			int LL = pre[p],RR = nxt[p + 1];
//			printf("? %lld %lld %lld %lld\n",LL,p,p + 1,RR);
			if(nxt[LL] == p + 1 && pre[RR] == p){
				ans += (f[LL] + 1) * (g[RR] + 1);
//				cout<<"! "<<LL<<" "<<RR<<" "<<f[LL] + 1<<" "<<g[RR] + 1<<'\n';
			}
			int xx = RR - 1,cc = 0,dd = 0;
			while(xx > p + 1){
				if(pre[xx] < p) break;
				if(pre[xx] == p){
					if(nxt[LL] == p + 1) ans += f[LL] + 1;
					cc++;
				}
				xx--;
			}
			xx = LL + 1;
			while(xx < p){
				if(nxt[xx] > p + 1) break;
				if(nxt[xx] == p + 1){
					if(pre[RR] == p) ans += g[RR] + 1;
					dd++;
				}
				xx++;
			}
//			printf("!!! %lld %lld\n",cc,dd);
			ans += cc * dd;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
