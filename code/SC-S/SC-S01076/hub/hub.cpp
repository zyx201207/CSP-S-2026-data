/*
感觉本质神秘。

考虑没有连通块最多两个的限制咋搞

是不是二分答案然后贪心的去做，首先你会了 k\leq 2

不过我现在想做 kn\log，这样有 75pts

想到说我们先贪心的
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e6+5;
const int inf=1e9+7;
int cid;
vector<int>mp[N];
int n,k;
inline void SubA(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
	}
	if(n==k){
		cout<<"0\n";
		return ;
	}
	int m=n/2+2;
	if(k>=m){
		cout<<"1\n";
		return ;
	}
	m-=(k-2);
	cout<<(m/3)+(m%3>1?1:0)<<'\n';
}
bool vis[N],col[N];
inline void dfs(int p){
	if(vis[p]||!col[p])return ;
	vis[p]=1;
	for(auto v:mp[p])dfs(v);
}
inline int calc(int p,int dis){
	if(col[p])return dis;
	if(vis[p])return 0;
	vis[p]=1;
	int dmax=0;
	for(auto v:mp[p])dmax=max(dmax,calc(v,dis+1));
	return dmax;
}
inline void solve(){
	if(cid==13||cid==14){
		SubA();
		return ;
	}
	cin>>n>>k;
	for(int i=1;i<=n;i++)mp[i].clear();
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	int V=(1<<n);
	int dmin=inf;
	for(int v=0;v<V;v++){
		for(int i=1;i<=n;i++)vis[i]=col[i]=0;
		int pop=0;
		for(int i=0;i<n;i++){
			if((v>>i)&1)pop++,col[i+1]=1;
		}
		if(pop!=k)continue;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&col[i])dfs(i),cnt++;
		}
		if(cnt>2)continue;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[j]=0;
			ans=max(ans,calc(i,0));
		}
//		cout<<"get one : v\n";
//		for(int i=1;i<=n;i++)cout<<col[i];
//		cout<<'\n';
//		cout<<ans<<'\n';
		dmin=min(dmin,ans);
	}
	cout<<dmin<<'\n';
}
signed main (){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int Case=1;cin>>cid>>Case;
	while(Case--)solve();
	return 0;
}