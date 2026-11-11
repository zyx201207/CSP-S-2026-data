#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=1e6+5;
int n,k;
vector<int>E[Maxn];
int V[Maxn],Col[Maxn],col,Cnt;
int Answer;
inline void DFS1(int nw) {
	if(Col[nw]==-1&&V[nw]) {
		Col[nw]=col;
		++col;
	}
	for(auto i:E[nw])
		if(V[nw]&&V[i]) {
			Col[i]=Col[nw];
			DFS1(i);
		}
}
inline bool Check() {
	col=1;
	memset(Col,-1,sizeof(Col));
	for(register int i=1; i<=n; ++i)
		cout<<V[i]<<" ";
	cout<<endl;
	Cnt=0;
	DFS1(1);
	for(register int i=1; i<=n; ++i)
		cout<<Col[i]<<" ";
	cout<<endl;
}
//inline int Get_Answer() {
//
//}
inline void Gen_Map(int nw,int cnt) {
	if(nw==n)
		return;
	if(cnt==k) {
		Check();
//		if(Check())
//			Answer=min(Answer,Get_Answer());
//		for(register int i=1; i<=n; ++i)
//			cout<<V[i]<<" ";
//		cout<<endl;
		return;
	}
	for(register int i=nw+1; i<=n; ++i) {
		V[i]=1;
		Gen_Map(i,cnt+1);
		V[i]=0;
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		Answer=1e18;
		for(register int i=1; i<=n; ++i) {
			E[i].clear();
			V[i]=0;
			Col[i]=0;
		}
		cin>>n>>k;
		for(register int i=1,u,v; i<=n-1; ++i) {
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
//		for(register int i=1; i<=n; ++i) {
//			for(auto j:E[i])
//				cout<<j<<" ";
//			cout<<endl;
//		}
		Gen_Map(0,0);
	}
	return 0;
}