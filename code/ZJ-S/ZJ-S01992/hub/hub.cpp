#include<bits/stdc++.h>
using namespace std;
int c,t; 
int n,k;
vector<int> e[200020]; 
bool vis[200020];
int depth[200020];
const int L=25;
int fa[200020][L];
int ans=0x3f3f3f3f;
void dfs(int u,int pa){
	fa[u][0]=pa;
	for(int v:e[u]){
		if(v==pa) continue;
		depth[v]=depth[u]+1;
		dfs(v,u);
	}
}
int LCA(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=L-1;i>=0;i--) if(depth[u]-(1<<i)>=depth[v]) v=fa[v][i];
	if(u==v) return u;
	for(int i=L-1;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int ta[200020];
int find(int x){
	return (ta[x]==x)?ta[x]:ta[x]=find(ta[x]);
}
void merge(int x,int y){
	ta[find(x)]=find(y);
}
void DFS(int dep,int last,vector<int> gh){
	if(dep>n) return;
	DFS(dep+1,last,gh);
	last--;
	gh.push_back(dep);
	if(last>0) {
		DFS(dep+1,last,gh);
		return;
	}
	for(int i=1;i<=n;i++){
		ta[i]=i;
	}
	int res=0;
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			int u=gh[i],v=gh[j];
			int lca=LCA(u,v);
			if((lca==u||lca==v)&&abs(depth[u]-depth[v])==1) merge(u,v);
			res=max(res,depth[u]+depth[v]-2*depth[lca]);
		}
	}
	sort(ta+1,ta+n+1);
	int x=0;
	for(int i=2;i<=n;i++){
		if(ta[i]==ta[i-1]) x++;
	}
	if(k-x<=2) ans=min(ans,res);
	
}
void solve(){
	depth[0]=-1;
	ans=0x3f3f3f3f;
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x); 
		if(n==1){
			cout<<"0\n";
			return;
		}
	if(k==2) {
		cout<<"1\n";
		return;
	}
	dfs(1,0);
	DFS(1,k,{});
	cout<<ans;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
    return 0;
}
/*
此时的时间已经所剩无几
我们也不打啥正解了
直接打个神秘部分分
估算一下这次CSP-S一等奖的分数线大概是在230左右 
这题我只需要拿12分的部分分在加上T3 8+8+8的部分分基本稳了 
等一下
k<=2是啥雷霆？
意思是直接输出1 吗？
主播主播，直接输出1还是太吃操作了，有没有更无脑的打法
孩子们，不用思考了，打个暴力结束了 
如果打7个测试点，我能获得28分，大大减少了C题的压力
 
前三个测试点只要一个雷霆dfs就能秒，啥阴 
不， 哪怕是打爆力，我也要打一个雷霆LCA展示操作 
不过我先打一个最基础的分数，其他的晚点打 
T3不想打了，把这个暴力打掉就算了 
*/
