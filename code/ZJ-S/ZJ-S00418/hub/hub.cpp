#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=100005;

int cas,T;
int n,k,ans;
int cho[N];
bool hub[N];

//int fa[N];
//int find(int x){
//	return x==fa[x]?x:fa[x]=find(x);
//}

vector<int> g[N];

bool check() {
	unordered_set<int> s;
	int tot=0;
	for(int i=1; i<=k; i++) {
		if(!s.count(cho[i]))tot++;
		if(tot>2)return 0;
		for(int v:g[cho[i]]) {
			s.insert(v);
		}
	}
	return 1;
}

int dis(int u,int fa) {
	if(hub[u])return 0;
	int res=1e6;
	for(int v:g[u]) {
		if(v==fa)continue;
		res=min(res,dis(v,u)+1);
	}
	if(res==3) {
//		cout<<u<<fa<<'\n';
	}
	return res;
}

void dfs(int la,int cnt) {
	if(cnt==k) {
		if(!check())return;
		int res=0;
		for(int i=1; i<=n; i++) {
			res=max(res,dis(i,0));
		}
		ans=min(ans,res);
//		if(T==1) {
//			for(int i=1;i<=n;i++){
//				if(hub[i])cout<<i<<' ';
//			}
//			cout<<'\n';
//			for(int i=1; i<=k; i++) {
//				cout<<cho[i]<<' ';
//			}
//			cout<<res<<' ';
//			cout<<'\n';
//		}
//		if(T==0) {
//			if(res==1) {
//				for(int i=1; i<=k; i++) {
//					cout<<cho[i]<<' ';
//				}
//				cout<<'\n';
//			}
//		}
		return;
	}
	for(int i=la+1; i<=n; i++) {
		hub[i]=1;
		cho[cnt+1]=i;
		dfs(i,cnt+1);
		hub[i]=0;
	}
}

signed main() {
//	fc hub.out hub2.ans
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cas>>T;
	while(T--) {
		cin>>n>>k;
		for(int u,v,i=1; i<n; i++) {
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=1e6;
		dfs(0,0);
		cout<<ans<<'\n';
		//clear(
		for(int i=1; i<=n; i++) {
			g[i].clear();
		}
	}

	return 0;
}

