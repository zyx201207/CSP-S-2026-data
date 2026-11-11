#include<bits/stdc++.h>
#define gbtbl ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define it long long
#define C cin
#define CC cout
#define ru >>
#define chu <<
#define cit const it
#define rt return
#define xiao_deng <=
#define da_deng >=
#define xiaoyu <
#define dayu >
#define rg if
#define fz else
#define pii pair<it,it>
#define ft first
#define sd second
#define pk push_back
using namespace std;
cit N=5e5+5;

it a[N];
it dis[N];
vector<pii>g[N];

void dijk(it st){
	priority_queue<it,vector<it>,greater<it>>q;
	q.push(st);
	while(!q.empty()){
		it u=q.top();
		q.pop();
		for(auto cur:g[u]){
			it v=cur.ft;
			it w=cur.sd;
			rg(dis[v]+w xiaoyu dis[u]){
				dis[u]=dis[v]+w;
				q.push(v);
			}
		}
	}
}

int main(){
	gbtbl
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	it c,n,m,d,t;
	C ru c ru n ru m ru d ru t;
	for(it i=1;i xiao_deng m;i++){
		C ru a[i];
	}
	for(it i=1;i xiao_deng n;i++){
		it x;
		C ru x;
		vector<it>u(x+5),w(x+5);
		for(it i=1;i xiao_deng x;i++){
			C ru u[i] ru w[i];
			g[u[i]].pk({u[i+1],w[i]});
			g[u[i+1]].pk({u[i],w[i]});
		}
	}
	while(t--){
		it st,ed;
		C ru st ru ed;
		dijk(st);
		CC chu dis[ed]+a[st]+a[ed] chu "\n";
	}
	
	rt 0;
}


/*
8 10
1 1 2 2 3 3 4 7
*/














