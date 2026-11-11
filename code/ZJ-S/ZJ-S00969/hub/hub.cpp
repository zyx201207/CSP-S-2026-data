#include <iostream>
#include <vector>
using namespace std;
const int N = 2000005, Inf = 2e9;
vector<int> G[N], Diam;
int DepthS[N], DepthT[N], Depth[N], Chosen[N], F[N][2];

int Dfs(int u, int f) {
	int Max=u, t=u;	Depth[u]=Depth[f]+1;
	for(int v: G[u]) if(v!=f)
		t=Dfs(v, u), Max=Depth[Max]<Depth[t]? t:Max;
	return Max;
}

void GetDepth(int u, int f, int* Depth) {
	Depth[u]=Depth[f]+1;
	for(int v: G[u]) if(v!=f)	GetDepth(v, u, Depth);
}

int Report(int u, int f, int* Depth) {
	int Max=Depth[u];
	for(int v: G[u]) if(v!=f)	Max=max(Max, Report(v, u, Depth));
	return Max;
}

bool FindPath(int u, int f, int t) {
	if(u==t)	return Diam.push_back(u), true;
	for(int v: G[u]) if(v!=f)
		if(FindPath(v, u, t))	return Diam.push_back(u), true;
	return false;
}

bool Check(int d, int n, int k, int S, int T) {
	//I don't know how to check?!
	int s=S, t=T;
	for(int u: Diam) {
		if(DepthS[u]>=DepthS[s] && DepthS[u]<=d)	s=u;
		if(DepthT[u]>=DepthT[t] && DepthT[u]<=d)	t=u;
	}
	return DepthT[S]-DepthT[s]<=d && DepthS[T]-DepthS[t]<=d;
}

int Main() {
	int n, k;	cin>>n>>k;
	for(int i=1;i<=n;i++)	G[i].clear();
	Diam.clear();
	for(int i=1, u, v;i<n;i++)
		cin>>u>>v, G[u].push_back(v), G[v].push_back(u);
	
	int s=Dfs(1, 0), t=Dfs(s, 0), l=0, r=n;
	GetDepth(s, 0, DepthS), GetDepth(t, 0, DepthT), FindPath(s, 0, t);
	
	for(int Mid=(l+r)/2;l<r;Mid=(l+r)/2)
		Check(Mid, n, k, s, t)? l=Mid+1:r=Mid;
	
	cout<<l<<'\n';
	return 0;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int T;	cin>>T;	while(T--) Main();
}
