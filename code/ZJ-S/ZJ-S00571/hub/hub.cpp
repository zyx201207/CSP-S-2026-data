#include <bits/stdc++.h>
#define endl '\n'
#define LAB
//#define DEBUG
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int,int>;
using pli = pair<ll,int>;
const int N = 3e2+10;

int CASE;
int fa[N];

int find(int x) {
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void merge(int x,int y) {
	int xf=find(x),yf=find(y);
	if(xf!=yf) fa[xf]=yf;
}

void Solve() {
	int n,k;
	cin>>n>>k;
	vector<int> tr[n+1],fa(n+10);
	bool con[n+10][n+10];
	memset(con,0,sizeof con);
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		tr[u].emplace_back(v);
		tr[v].emplace_bacK(u);
		con[u][v]=con[v][u]=1;
	} 
	for(int S=0;S<(1<<n);S++) {
		for(int i=1;i<=n;i++) fa[i]=i;
		int cnt=0,tmp=S;
		while(tmp) cnt+=(tmp&1),tmp>>=1;
		if(cnt!=k) continue;
		vector<int> p;
		for(int i=1;i<=n;i++) {
			if(S&(1<<i-1)) p.emplace_back(i);
		} for(int i=0;i<p.size();i++) {
			for(int j=i=1;j<p.size();j++) {
				if(con[i][j]) merge(i,j);
			}
		} set<int> s;
		for(int i=1;i<=n;i++) s.insert(fa[i]);
		if(i>2) continue;
	} 
	
	
	cout<<1<<endl;
	
	
}


int main() {
	#ifdef LAB
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>CASE;
	
	int T;
	cin>>T;
	while(T--) Solve();
	
	return 0;
}


