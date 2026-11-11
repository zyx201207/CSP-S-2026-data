#include <cstdio>
#include <cctype>
#include <vector>
#include <climits>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
namespace ly{
	namespace IO{
		#define SIZE (1<<20)
		char in[SIZE],out[SIZE],*p1=in,*p2=in,*p3=out;
		#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,SIZE,stdin),p1==p2)?EOF:*p1++)
		#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
		#define putchar(ch) (p3==out+SIZE&&flush(),*p3++=(ch))
		class Flush {
			public:~Flush() {
				flush();
			}
		}_;
		template<typename T>
		inline void read(T&x) {
			x=0;bool flag=0;char ch=getchar();
			while (!isdigit(ch)) flag=ch=='-',ch=getchar();
			while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
			flag?x=-x:0;
		}
		template<typename T>
		inline void write(T x,bool flag=0) {
			x<0?x=-x,putchar('-'):0;
			static short Stack[105],top;top=0;
			do Stack[++top]=x%10,x/=10;while (x);
			while (top) putchar(Stack[top--]|48);
			flag?putchar('\n'):putchar(' ');
		}
		#undef SIZE
		#undef getchar
		#undef putchar
		#undef flush 
	}
}using namespace ly::IO;
typedef long long ll;
const int M=5*100000+9;
vector<ll> e[10*M],w[10*M]; // 1~m点代表地铁口，,m+1~2m点代表站厅 。 
ll c,n,m,d,q;
void make_edge(ll a,ll b,ll wi) {
	e[a].push_back(b);
	e[b].push_back(a);
	w[a].push_back(wi);
	w[b].push_back(wi);
}
ll dis[10*M];
bool ok[10*M];
map<ll,ll> mp;
struct CMP {
	bool operator()(pair<ll,ll>a,pair<ll,ll>b) {
		return a.second>b.second;
	}
};
void Dijkstra(ll start) {
	memset(ok,0,sizeof ok);
	fill(dis,dis+10*M,LLONG_MAX);
	dis[start]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,CMP>pq;
	pq.push(make_pair(start,0ll));
	while (pq.size()) {
		auto top=pq.top();
		pq.pop();
		ll u=top.first;
		if (top.second>dis[u]) continue;
		ok[u]=1;
		for (int i=0;i<e[u].size();i++) {
			ll v=e[u][i];
			ll wi=w[u][i];
			if (dis[v]>dis[u]+wi) {
				dis[v]=dis[u]+wi;
				pq.push(make_pair(v,dis[v]));
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n),read(m),read(d),read(q);
	for (int i=1;i<=m;i++) {
		ll x;read(x);
		make_edge(i,m+i,x);
	}
	ll cur_nodes=2*m+1;
	for (int i=1;i<=n;i++) {
		ll len;read(len);
		ll last=1;
		for (int j=1;j<=len;j++) {
			ll a,t;
			read(a),read(t);
			a+=m;
//			write(a),write(cur_nodes),write(last),write(t,1); 
			make_edge(cur_nodes,a,t);
			if (j!=1) {
				make_edge(cur_nodes,last,0);
				last=cur_nodes;
			} else {
				last=cur_nodes;
			}
			cur_nodes++;
		}
	}
	for (int i=1;i<=q;i++) {
		ll start,end;
		read(start),read(end);
		Dijkstra(start);
		write(dis[end],1);
	}
//	for (int i=1;i<=10000;i++){
//		for (int j=0;j<w[i].size();j++) {
//			printf("%d->%d:%d\n",i,e[i][j],w[i][j]);
//		}
//	}
	return 0;
}
