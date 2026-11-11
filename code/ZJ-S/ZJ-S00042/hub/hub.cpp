#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int inf=0x3f3f3f3f;
int n,k,lg[N];
int dep[N],fa[20][N];
int head[N],nxt[N<<1],to[N<<1],ecnt;
void add(int x,int y){
	nxt[++ecnt]=head[x];
	head[x]=ecnt;
	to[ecnt]=y;
	return;
}
void dfs(int x=1,int f=0){
	fa[0][x]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f)continue;
		dfs(to[i],x);
	}
	return;
}
int get_lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[lg[dep[x]-dep[y]]][x];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;--i)
		if(fa[i][x]!=fa[i][y])
			x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int get_dis(int x,int y){return dep[x]+dep[y]-2*dep[get_lca(x,y)];}
namespace subtask1{
	inline int count(int x){
		int cnt=0;
		while(x)cnt+=(x&1),x>>=1;
		return cnt;
	}
	int belong[N];
	int find(int x){return x==belong[x]?x:belong[x]=find(belong[x]);}
	inline bool check(int S){
		int tot=k;
		for(int i=1;i<=n;++i)belong[i]=i;
		for(int i=1;i<=n;++i){
			if((S>>(i-1))&1){
				for(int j=head[i];j;j=nxt[j]){
					if((S>>(to[j]-1))&1){
						if(find(to[j])==find(i))continue;
						belong[find(to[j])]=find(i);
						--tot;
					}
				}
			}
		}
		return tot<=2;
	}
	inline int get_r(int S){
		int r=0;
		for(int i=1,d;i<=n;++i){
			d=inf;if((S>>(i-1))&1)continue;
			for(int j=1;j<=n;++j){
				if((S>>(j-1))&1)
					d=min(d,get_dis(i,j));
			}
			r=max(r,d);
		}
		return r;
	}
	void solve(){
		int res=inf;
		for(int S=0;S<(1<<n);++S){
			if(check(S)&&count(S)==k)res=min(res,get_r(S));
		}
		cout<<res<<'\n';
		return;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs();
	if(n==k){
		cout<<0<<'\n';
		for(int i=1;i<=n;++i)head[i]=0;
		ecnt=0;
		return;
	}
	if(n<=10){
		subtask1::solve();
		for(int i=1;i<=n;++i)head[i]=0;
		ecnt=0;
		return;
	}
	//15pts
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=2;i<N;++i)lg[i]=lg[i>>1]+1;
	int _=1,c;cin>>c>>_;
	while(_--)solve();
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
//freopen("hub.in","r",stdin);
今年又考爆炸了呜呜呜 
 不知道什么时候睡着了
 一觉醒来发现少了1h
 100+44+40+15
 别挂分
 还有半小时看看能不能赢
关注洛天依谢谢喵
 
*/
