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
#define Freopen
#define N 2000010
int n,d,a[N],dis[N],num[N];
bool vis[N],cnt[N];
vector<int>e[N];
const int inf=(int)INFINITY>>2;
inline void init(){
	for(int i=1;i<=n;++i){
		e[i].clear();
		cnt[i]=0;
	}
}
inline int dj(int s){
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;++i){
		dis[i]=num[i]=vis[i]=0;
	}
	vis[s]=num[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:e[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
				dis[v]=dis[u]+1;
				num[v]=num[u];
			}
			else if(dis[v]==dis[u]+1){
				num[v]+=num[u];
			}
		}
	}
	int sum(0);
	for(int i=1;i<=n;++i) sum+=(num[i]==2);
	return sum;
}
inline void work1(){
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[j]-a[i]<=d){
				e[i].emplace_back(j);
				e[j].emplace_back(i);
				cnt[i]=cnt[j]=1;
			}
			else break;
		}
	}
	int ans(0);
	for(int i=1;i<=n;++i){
		ans+=dj(i);
	}
	write(ans>>1,'\n');
}
inline void work(){
	read(n,d);
	init();
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	if(n<=5000) return work1(),void(0);
}
int c,t;
signed main(){
	#ifdef Freopen
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	read(c,t);
	while(t--) work();
	return 0;
}