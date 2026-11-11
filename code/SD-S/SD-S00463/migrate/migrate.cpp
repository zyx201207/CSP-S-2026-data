#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define F(s) freopen(#s ".in","r",stdin);\
	freopen(#s ".out","w",stdout)
using namespace std;
namespace FastIO{
	#ifdef __linux__
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#else
	#define gc _getchar_nolock
	#define pc _putchar_nolock
	#endif
	inline bool blank(char x){
		return !(x^32)||!(x^10)||!(x^13)||!(x^9);
	}
	template<typename Tp>
	inline void read(Tp& x){
		x=0;
		bool f=true;
		char ch=gc();
		for(;!isdigit(ch);ch=gc())
			if(ch=='-') f=false;
		for(;isdigit(ch);ch=gc())
			x=(x<<1)+(x<<3)+(ch^48);
		x=(f?x:~x+1);
	}
	inline void read(char& x){
		for(x=gc();blank(x)&&(x^-1);x=gc());
	}
	inline void read(char* x){
		char ch=gc();
		for(;blank(ch)&&(ch^-1);ch=gc());
		for(;!blank(ch)&&(ch^-1);ch=gc())
			*x++=ch;
		*x=0;
	}
	inline void read(string& x){
		x="";
		char ch=gc();
		for(;blank(ch)&&(ch^-1);ch=gc());
		for(;!blank(ch)&&(ch^-1);ch=gc())
			x+=ch;
	}
	template<typename T,typename... Tp>
	inline void read(T& x,Tp&... y){read(x),read(y...);}
	template<typename Tp>
	inline void write(Tp x){
		if(!x) return pc(48),void();
		if(x<0) pc('-'),x=~x+1;
		int len=0; char tmp[64];
		for(;x;x/=10) tmp[++len]=x%10^48;
		while(len) pc(tmp[len--]);
	}
	inline void write(const char x){pc(x);}
	inline void write(const bool x){pc(x?49:48);}
	inline void write(char* x){fputs(x,stdout);}
	inline void write(const char* x){fputs(x,stdout);}
	inline void write(const string& x){fputs(x.c_str(),stdout);}
	template<typename T,typename... Tp>
	inline void write(T x,Tp... y){write(x),write(y...);}
}
using namespace FastIO;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=5e5+10;
int n,dis,x[N],cnt[N];
struct Heap{
	ll d;
	int id;
	bool operator <(Heap b)const{
		return d>b.d;
	}
};
priority_queue<Heap> q;
vector<int> e[N];
bitset<N> vis;
int d[N];
inline void dij(int s){
	memset(d,0x3f,(n+1)*sizeof(int));
	memset(cnt,0,(n+1)*sizeof(int));
	while(!q.empty()) q.pop();
	vis=d[s]=0,cnt[s]=1,q.push({0,s});
	while(!q.empty()){
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v:e[u]){
			if(d[u]+1<d[v]){
				cnt[v]=cnt[u];
				d[v]=d[u]+1;
				q.push({d[v],v});
			}
			else if(d[u]+1==d[v]) cnt[v]+=cnt[u];
		}
	}
}
inline void solve(){
	read(n,dis);
	for(int i=1;i<=n;i++) read(x[i]);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>dis) break;
			e[i].emplace_back(j);
			e[j].emplace_back(i);
		}
	int ans=0;
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
	}
	write((ans>>1),'\n');
}
signed main(){
	F(migrate);
	int c,t; read(c,t);
	while(t--) solve();
	return 0;
}
