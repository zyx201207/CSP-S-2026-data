#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int c,t;
int n,k,ans[35][35],mi=1e16;
int u[35],v[35],a[35],ch[35],f[35],qq[35];
bool vis[46];
vector<int>e[1000006];
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
void add(int x,int y){
	f[find(x)]=find(y);
}
bool check(int p){
	for(int i=1;i<=p;i++)f[ch[i]]=ch[i];
	for(int i=1;i<=ch[i];i++)
		for(int j:e[ch[i]]){
			if(find(i)!=find(j))add(j,i);
		}
	int s=1,l=0;
	memset(qq,0,sizeof(qq));
	for(int i=1;i<=p;i++){
		qq[f[ch[i]]]++;
	}
	for(int i=1;i<=n;i++)
		if(qq[i]!=0)l++;
	
	return l<=2;
}
void bfs(int x){
	queue<pair<int,int>>q;
	q.push({x,0});vis[x]=1;
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		auto g=q.front();q.pop();
//		cout<<g.fi<<' '<<g.se<<'\n';
		ans[x][g.fi]=g.se;
		for(int j:e[g.fi]){
			if(!vis[j])vis[j]=1,q.push({j,g.se+1});
		}
	}
}
int q(int p){
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=p;i++){
		bfs(i);
	}
	int mx=-1;
	for(int i=1;i<=n;i++){
		int mi=1e14;
		for(int j=1;j<=p;j++){
			mi=min(mi,ans[i][ch[j]]);
//			cout<<ans[i][j]<<' ';
		}
// 		cout<<'\n';
		mx=max(mx,mi);
	}
//	cout<<'\n';
	return mx;	
}
void dfs(int x,int p){
	if(x==n+1&&p==k){
		if(check(p)){
			mi=min(mi,q(p));
		}
//		for(int i=1;i<=k;i++)cout<<ch[i]<<' ';
	}
	if(p>k||x>=n+1)return;
	ch[++p]=x;
	dfs(x+1,p);
	ch[p--]=0;
	dfs(x+1,p);
}
void init(){
	cin>>n>>k;
//	cout<<'\n';
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i],
		e[v[i]].push_back(u[i]),
		e[u[i]].push_back(v[i]);
	}
	dfs(1,0);
	cout<<mi<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)init();
	return 0;
}
/*
16:26 O(n^2*2^n)
T1 is easy,but T2,T3,T4 is hardddddddddddddddddddddd.
其他n座城分别到选择方案的每座城的距离中最小值的最大值 
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

*/
