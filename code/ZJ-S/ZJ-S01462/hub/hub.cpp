#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e4+10,INF=1e18;

int n,k,fa[N],f[N],mx,ans;
vector<int> g[N];
bool st[N];/* 需要用的点 */

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]==x;
}

int lowbit(int x){
	return x&-x;
}
int js(int x){
	int sum=0;
	while(x){
		sum++;
		x-=lowbit(x);
	}
	return sum;
}

void dfs1(int x,int faa,int col){
	fa[x]=col;
	for(auto v:g[x]){
		if(v==faa) continue;
		if(st[x]==0) continue;
		dfs1(v,x,col);
	}
}

bool vis[N];
void dfs(int x,int faa,int len){
	vis[x]=1;
	if(len==0) return;
	for(auto v:g[x]){
		if(v==faa) continue;
		dfs(v,faa,len-1);
	}
}

bool check(int x){
	bool flag=1;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) if(st[i]==1) vis[i]=1;
	for(int i=1;i<=n;i++) if(st[i]==1) dfs(i,0,x);
	for(int i=1;i<=n;i++) if(vis[i]==0) flag=0;
	return flag;
}

void solve(){
	cin>>n>>k;
	if(n>30){
		cout<<(k+1)/2<<"\n";
		return;
	}
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=INF;
	for(int i=0;i<(1<<n);i++){
		if(js(i)<k||js(i)>k) continue; 
		for(int j=1;j<=n;j++) st[j]=0,fa[j]=j;
		int cnt=0;
		if(js(i)==k){
			for(int j=0;j<n;j++){
				if((i&(1<<j))) st[j+1]=1;
			}
			for(int j=1;j<=n;j++){
				if(st[j]==0) continue;
				if(fa[j]==j){
					dfs1(j,0,j);
					cnt++;
				}
				if(cnt>2) break;
			}
			if(cnt>2) continue;
			int now=-1;
			for(int j=1;j<=n;j++){
				mx=-1;
				if(fa[j]==j){
					int L=1,R=n,mid=L+R>>1;
					while(L<=R){
						mid=L+R>>1;
						if(check(mid)==1){
							mx=mid;
							R=mid-1;
						}else L=mid+1;
					}
//					cout<<mx<<"\n";
				}
				now=max(now,mx);
			}
			if(now!=-1) ans=min(ans,now);
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T; cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

15分 乱打
k个点 形成不超过两个连通块 
且连通块的直径值最小
求最小直径数 
*/
