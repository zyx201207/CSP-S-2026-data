#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int c,t;
constexpr int N = 1000005;
int n,k;

using pii = pair<int, int>;

struct p_d{
	int p, d;
};

bool operator<(const p_d& a, const p_d& b){
	return a.d<b.d;
}

struct run{
	vector<vector<int>> g;
	vector<bool> vis;
	vector<int> st_max_dep;
	
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	pii dfs1(int p, int fa){
		pii mx = {p, 0};
		for(int v: g[p]){
			if(v==fa) continue;
			pii n = dfs1(v, p);
			n.second+=1;
			if(n.second>mx.second) mx=n;
		}
		return mx;
	}
	
	int max_dep = 0;
	vector<int> road;
	bool dfs2(int p, int fa, int dep){
		if(fa!=0 && g[p].size()==1){
			if(dep>max_dep){
				road[dep]=p;
				max_dep = dep;
				return true;
			}
			return false;
		}
		bool win = false;
		
		for(int v:g[p]){
			if(v==fa) continue;
			win = win || dfs2(v, p, dep+1);
		}
		if(win) road[dep]=p;
		return win;
	}
	
	int top = 0;
	void dfs3(int p, int fa){
		int smd = 0;
		for(int v:g[p]){
			if(v==fa) continue;
			dfs3(v, p);
			smd=max(smd, st_max_dep[v]);
		}
		st_max_dep[p]=smd+1;
	}
	
	void pt(){
		cin>>n>>k;
		g.resize(n+1);
		vis.resize(n+1);
		st_max_dep.resize(n+1);
		road.resize(n+1);
		
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			add_edge(u, v);
		}
		
		pii m1 = dfs1(1, 0);
		dfs2(m1.first, 0, 1);
		top = road[1+max_dep/2];
		dfs3(top, 0);
		
		priority_queue<p_d> cand;
		cand.push({top, st_max_dep[top]});
		
		int rem = k;
		while(rem--){
			p_d i = cand.top();
			cand.pop();
			vis[i.p] = 1;
			for(int v: g[i.p]){
				if(vis[v]) continue;
				cand.push({v, st_max_dep[v]});
			}
		}
		
		if(cand.empty()){
			cout<<0<<endl;
		}else{
			cout<<cand.top().d<<endl;
		}
	}
};


int main(){
	freopen("hub1.in", "r", stdin);
	cin>>c>>t;
	
	for(int i=1;i<=t;++i){
		run().pt();
	}
}
