#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
template<typename T>
inline bool read(T &x){
	x=0;bool f=0;int c=gc();
	for(;!isdigit(c);c=getchar()){
		if(!(~c)) return 0;
		if(c=='-') f=1;
	}
	for(;isdigit(c);c=gc()){
		x=(x<<3)+(x<<1)+(c^'0');
	}
	return x=f?-x:x,1;
}
template<typename A,typename...B>
int read(A &x,B&...y){
	return read(x)+read(y...);
}
inline void Write(char c){
	pc(c);
}
template<typename T>
void Write(T x){
	if(x<0) x=-x;
	if(x<10) return pc(x^'0'),void(0);
	Write(x/10),pc((x%10)^48);
}
inline int write(){return 0;}
template<typename A,typename...B>
int write(A x,B ...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
//using ll=long long;
#define Freopen
#define N 510
#define M 500010
int c,n,m,d,q,w[M],f[M],dp[M];
bool vis[M];
vector<int>a[N],t[N];
vector<pair<int,int>>line[M];
set<int>useful;
set<int>boss;
const int inf=(int)INFINITY>>2;
int Find(int x){return f[x]==x?x:f[x]=Find(f[x]);}
inline void merge(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y) f[x]=y;
}
void dfs(int x,int time){
	if(time>=dp[x]) return;
	dp[x]=time;
	vis[x]=1;
	for(auto SUB:line[x]){
		int sub=SUB.first;
		if(boss.find(Find(sub))!=boss.end()){
			int len=a[sub].size();
			for(int i=0;i<len;++i){
				int sta=a[sub][i];
				if(sta!=x&&!vis[sta]) dfs(sta,time+t[sub][i]);
			}
		}
	}
	vis[x]=0;
}
signed main(){
	#ifdef Freopen
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	read(c,n,m,d,q);
	for(int i=1;i<=m;++i){
		read(w[i]);
		f[i]=i;
	}
	for(int i=1,k;i<=n;++i){
		read(k);
		for(int j=1,A,T;j<=k;++j){
			read(A,T);
			a[i].emplace_back(A);
			t[i].emplace_back(T);
			line[A].emplace_back(i,T);
		}
	}
	for(int i=1;i<=m;++i){
		int len=line[i].size();
		if(len<2) continue;
		for(int j=1;j<len;++j){
			merge(line[i][j-1].first,line[i][j].first);
		}
	}
	for(int i=1,l,r;i<=q;++i){
		read(l,r);
		for(auto sub:line[r]){
			boss.insert(Find(sub.first));
		}
		for(int i=1;i<=m;++i) dp[i]=inf;
		dfs(l,w[l]);
		write(dp[r]+w[r],'\n');
	}
	return 0;
}
