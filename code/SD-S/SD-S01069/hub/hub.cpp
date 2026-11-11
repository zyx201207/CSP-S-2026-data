#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 110;
vector<int> a[N];
int n,k,dis[N][N],vi[N],b[N],Mi;
void dfs1(int x,int fa,int rt) {
	for(int i=0;i<a[x].size();i++) {
		int y=a[x][i];
		if(y!=fa) {
			dis[rt][y]=dis[rt][x]+1;
			dfs1(y,x,rt); 
		} 
	}
}
int find(int x) {
	if(b[x]==x) return x;
	return b[x]=find(b[x]);
}
bool check() {
	for(int i=1;i<=n;i++) b[i]=i;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<a[i].size();j++) {
			int x=i,y=a[i][j];
			if(vi[x]&&vi[y]) {
				b[find(x)]=find(y);
			}
		}
	}
	map<int,int> M;
	for(int i=1;i<=n;i++) {
		if(vi[i]) {
			M[find(i)]=1;
		}
	}
	if(M.size()<=2) return 1;
	else return 0;
}
int getsum() {
	int ans=0;
	for(int i=1;i<=n;i++) {
		int mi=n+1;
		for(int j=1;j<=n;j++) {
			if(vi[j]) {
				mi=min(mi,dis[i][j]);
			}
		}
		ans=max(ans,mi);
	}
	return ans;
}
void dfs(int x,int ans) {
	if(ans==k) {
		if(check()) {
			Mi=min(Mi,getsum());
		}
		return;
	}
	if(x>n) return;
	vi[x]=1;
	dfs(x+1,ans+1);
	vi[x]=0;
	dfs(x+1,ans); 
}
void solve() {
	cin>>n>>k;
	Mi=n+1;
	for(int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		dis[i][i]=0;
		dfs1(i,0,i);
	}
	dfs(1,0);
	cout<<Mi<<'\n';
	for(int i=1;i<=n;i++) a[i].clear();
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--) solve(); 
	return 0;
}
/*
拉倒吧炸飞了
100 +  32~60 + 8 + 12
运气好点 
100 +  44~60 + 8 + 12

哈哈哈我真服了一等线不知道有多高....
bye bye了CCF 
*/
