#include <bits/stdc++.h>
using namespace std;

int const N=1000010;
int c,t;
int n,k,idx;
int head[N],Next[N<<1],ver[N<<1];
int maxx,p,res=1e9;
bool vis[N],f[N];

void edge(int a,int b){
	Next[++idx]=head[a],head[a]=idx,ver[idx]=b;
	Next[++idx]=head[b],head[b]=idx,ver[idx]=a;
	return;
}

struct node{
	int x,s;
};

void dfs2(int x){
	int y;
	vis[x]=1;
	for (int i=head[x];i;i=Next[i]){
		y=ver[i];
		if (vis[y] || !f[y]) continue;
		dfs2(y);
	}
	return;
}

bool judge(){
	if (k==n) return 1;
	int x,cnt=0;
	memset(vis,0,sizeof(vis));
	for (x=1;x<=n;x++){
		if (f[x] && !vis[x]) {
			dfs2(x);cnt++;
		}
	}
	return cnt<=2;
}

int bfs(int x){
	if (f[x]) return 0;
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(node{x,0});
	node t;int y;
	while (q.size()){
		t=q.front();q.pop();
		vis[t.x]=1;
		for (int i=head[t.x];i;i=Next[i]){
			y=ver[i];
			if (vis[y]) continue;
			if (f[y]) return t.s+1;
			q.push(node{y,t.s+1});
		}
	}
	return 0;
}

void calc(){
	if (!judge()) return;
	int tmp;maxx=0;
	for (int i=1;i<=n;i++){
		tmp=bfs(i);
		maxx=max(maxx,tmp);
	}
	res=min(res,maxx);
	return;
} 

void dfsm(int x,int s){
	if (x>n){
		calc();
	}
	else{
		if (s){
			f[x]=1; 
			dfsm(x+1,s-1);
			f[x]=0;
		} 
		if (n-x+1>s) dfsm(x+1,s);
	}
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	int u,v;
	for (int x=1;x<=t;x++){
		res=1e9;
		memset(f,0,sizeof(f));
		memset(head,0,sizeof(head));
		memset(Next,0,sizeof(Next));
		memset(ver,0,sizeof(ver));
		scanf("%d %d",&n,&k);
		for (int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			edge(u,v);
		}
		dfsm(1,k);
		printf("%d\n",res);
	}
	
	return 0;
}
//jun bu jian huang he zhi shui tian shang lai.ben liu dao hai bu fu hui.jun bu jian gao tang ming jing bei bai fa.zhao ru qing si mu cheng xue.tian sheng wo cai bi you yong.qian jin san qu huan fu lai.peng yang zai niu qie wei le.hui xu yi yin san bai bei.\qian fu zi.dan qiu sheng.qiang jin jiu.bei mo ting.yu jun ge yi qu.qing jun wei wo qing er ting.zhong gu zhuan yu bu zu gui.dan yuan chang zui bu yuan xing.gu lai sheng xian jie ji mo.wei you yin zhe liu qi ming.xi shi chen wang yan ping le.dou jiu shi qian zi huan xue.zhu ren he xu yan shao qian.jing xu gu qu dui jun zhuo.wu hua ma.qian jin qiu.hu er jiang chu huan mei jiu.yu er tong xiao wan gu chou.

