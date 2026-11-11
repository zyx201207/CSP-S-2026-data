//外来之人，你的旅途到此为止了 
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffffffffffff
using namespace std;
int c,n,m,lim,q;
ll w[100030];
class node{
public:
	ll d;bool f;
	node(ll _d=inf):d(_d),f(0){}
};
vector<node> p;
class edge{
public:
	int v;ll w;
	edge(int _v=0,ll _w=0):
		v(_v),w(_w){}
};
vector<edge>g[500030+500];
class K1{
public:
	int pos;
	ll d;
	K1(int _pos=0,ll _d=0):
		pos(_pos),d(_d){}
	bool operator> (const K1& b)const{
		return d>b.d;
	}
};
#define Heap priority_queue<K1,vector<K1>,greater<K1> >
Heap heap;
ll dijistra(int st,int en){
	p=vector<node>(n+m+30);
	heap=Heap();
	p[st].d=0;
	heap.push(K1(st,0));
	while(!heap.empty()){
		auto t=heap.top();
		heap.pop();
		if(p[t.pos].f) continue;
		p[t.pos].f=1;
		if(t.pos==en){
			return t.d;
		}
		for(auto &x : g[t.pos]){
			if(!p[x.v].f && t.d+x.w<p[x.v].d){
				p[x.v].d=t.d+x.w;
				heap.push(K1(x.v,p[x.v].d));
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>lim>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int tn;cin>>tn;
		if(tn==1){
			cin>>tn>>tn;
			n--;i--;
			continue;
		}
		for(int j=1;j<=tn;j++){
			int t;ll tw;cin>>t>>tw;
			if(t>m) continue;
			g[m+i].push_back(edge(t,tw));
			g[t].push_back(edge(m+i,tw));
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		printf("%lld\n",dijistra(x,y)+w[x]+w[y]);
	}
	return 0;
}
//CCF are you OK???
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll cnt;
ll t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway6.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	while(cin>>t){
		cnt++;	
	}
	printf("%lld %lld",cnt,m+n*(1+2*m)+q*2);
	return 0;
}
//output: 1620001 461000161
*/
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll cnt;
ll t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway7.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	while(cin>>t){
		cnt++;	
	}
	printf("%lld %lld",cnt,m+n*(1+2*m)+q*2);
	return 0;
}
//output: 1620001 461000161
*/
/*
输入的第一行包含五个非负整数 c, n, m, d, q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例。
输入的第二行包含 m 个正整数 w1, w2, . . . , wm，依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2ki 个正整数，其中第一个正整数为 ki，表
示第 i 条线路经过的地铁站数；接下来 2ki 个正整数为 a_{i,1}, t_{i,1}, a_{i,2}, t_{i,2}, . . . , a_{i,ki}
, t_{i,ki}，其
中 a_{i,j} 表示第 i 条线路经过的第 j 个地铁站，t_{i,j} 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 xr, yr，分别表示第 r 个出行计
划的起点和终点所在的地铁站编号。
对于所有测试数据，均有：
0 ≤ c ≤ 25，1 ≤ n ≤ 500，1 ≤ m ≤∑_i=1^n{ki} ≤ 5 × 10^5，1 ≤ d ≤ 20，1 ≤ q ≤ 10^5；
? 对于所有 v (1 ≤ v ≤ m)，均有 1 ≤ wv ≤ 10^9；
? 对于所有 i (1 ≤ i ≤ n)，均有 1 ≤ ki ≤ m；
? 对于所有 i, j (1 ≤ i ≤ n, 1 ≤ j ≤ ki)，均有 1 ≤ ai,j ≤ m，1 ≤ ti,j ≤ 10^9；
? 对于所有 i (1 ≤ i ≤ n)，均有 a_{i,1}, a_{i,2}, . . . , a_{i,ki} 两两不同；
? 对于所有 v (1 ≤ v ≤ m)，经过第 v 个地铁站的线路数均不超过 d；
? 任意两个地铁站都可以通过若干条线路互相到达；
? 对于所有 r (1 ≤ r ≤ q)，均有 1 ≤ xr, yr ≤ m，且 xr != yr。
*/ 
