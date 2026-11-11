#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn],ans[maxn],now[maxn],cnt[maxn],fa[maxn];
vector<int>G[maxn];
int siz[maxn];
void dfs(int u,int F){
	ans[u]=cnt[u];
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==F)continue; 
		dfs(v,u);
		ans[u]+=ans[v];
	}
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		s[i]=now[a[i]];
		now[a[i]]=i;
		cnt[a[i]]++;
	}
//	for(int i=n;i>=1;i--){
//		if(s[i]==0){
//			for(int j=1;j<=m;j++)t[a[i]][j]=t[a[i+1]][j];
//			t[a[i]][a[i]]=1;
//		}
//	} 
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++)ans[j]+=t[i][j]*cnt[i];
//	}
//	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			G[a[i]].push_back(a[i+1]);
			G[a[i+1]].push_back(a[i]);
		}
	}
	dfs(a[n],0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
9:36
去了个厕所 
9:42
打个暴力找找规律吧，这才1h多 
打一半想水一会才发现这是CSP
10:02了
还是不会，还有俩小时，找不到规律啊，还是自己想一会吧
10:39
会nm了，感觉很好优化 
每个点一个转移点，相当于每个只有一个父亲，还有一个根，这就是树直接在这棵树上dfs就完了？ 
祖先集合咋写，哦哦转成每个点子树的贡献就行了 
不对，联通吗？ 
应该联通吧 ，没有重边自环 

10:54 AK了

最慢之区 ，冻死我了，还好这老爷机好热，暖暖手 。 

感觉所有题都很有把握啊，懒得打拍子了，挂分就挂分，个人红黄黄绿。 
不困还冷睡不着 ，就这样吧，不拍了检查一遍没错。 

11:08 暖和了，等会干啥呀，打板子（模板）打以及打板子（phi） 

睡一会吧为下午做准备，建一下文件夹，写一下表。
嗯，就这样 
*/
