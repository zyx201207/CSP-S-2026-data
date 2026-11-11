#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch = getchar();
	}
	return ans*f;
}

struct dsu{
	vector<int> pa,sz;
	int cnt;
	dsu(int _n){
		cnt = _n;
		pa = sz = vector<int>(cnt+1,1);
		iota(pa.begin(),pa.end(),0);
	}
	int find(int x){
		return x == pa[x] ? x : pa[x] = find(pa[x]);
	}
	void merge(int u,int v){
		u = find(u),v = find(v);
		if(u==v) return;
		if(sz[u]<sz[v]) swap(u,v);
		pa[v] = u;
		sz[u] += sz[v];
		cnt--;
	}
	bool pd(int u,int v){
		return find(u) == find(v);
	}
};
struct edge{
	int u,v,w;
	bool operator < (const struct edge& rhs) const {
		return w<rhs.w;
	}
};


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	
	return 0;
}
