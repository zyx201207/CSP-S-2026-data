/*
不是今年这T1T2咋这么简单
T3应该也不难，不过我比较菜就是了
感觉大众分350了啊啊啊咋办咋办这我不是废了
有生之年真的有机会去WC吗，感觉对我而言还是太困难了一点
能不能那天晚上做梦直接继承老父亲的编程水平跃升大神
为啥我这么笨呢鹅鹅鹅饿 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int c,t;
int n,k;
struct node{
	int next,to;
}e[MAXN<<1];
int head[MAXN],cnt;
int dep[MAXN],par[MAXN][30];
void add(int a,int b){
	e[++cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
	return ;
}
void dfs(int fa,int x){
	dep[x]=dep[fa]+1;
	par[x][0]=fa;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
	}
	return ;
}
void getpar(){
	for(int j=1;j<=25;j++){
		for(int i=1;i<=n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	return ;
}
int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]<dep[y]) swap(x,y);
	for(int j=25;j>=0;j--){
		if(dep[par[x][j]]>=dep[y]) x=par[x][j]; 
	}
	if(par[x][0]==par[y][0]) return par[x][0];
	if(x==y) return x;
	for(int j=25;j>=0;j--){
		if(par[x][j]!=par[y][j]){
			x=par[x][j];
			y=par[y][j];
		}
	} 
	return par[x][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(head,0,sizeof head);
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			add(u,v);add(v,u);
		}
		dfs(1,0);
		if(k==n){
			cout<<0<<"\n";
		}
	}
	return 0;
}
