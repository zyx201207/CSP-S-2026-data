#include<bits/stdc++.h>
using namespace std;
int const N=2e6+1,inf=0x3f3f3f3f;
vector<int> g[N];
bitset<N> vis;
long long a[N];
int dis[N],cnt[N];
long long d;
int c,T,n,ans;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vis.reset();
	for(int i=1;i<=n;++i){
		dis[i]=inf;
		cnt[i]=0;
	}
	dis[s]=0;
	cnt[s]=1;
	pq.push({0,s});
	while(!pq.empty()){
		int u=(pq.top()).second;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis.set(u);
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				pq.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
			}
		}
	}
}
/*
到底是谁在楼下又学猫叫又学狼嚎又学狗吠的啊？！
*/
void prep(){
	for(int i=1;i<=n;++i){
		g[i].clear();
		g[i].shrink_to_fit();
	}
}
void solve(){
	if(c<=10){
		prep();
		//建图
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}
			}
		}
		//跑最短路
		ans=0;
		for(int i=1;i<n;++i){
			dijkstra(i);
			for(int j=i+1;j<=n;++j){
				ans+=(cnt[j]==2);
			}
		}
	}
	else if(13<=c&&c<=14){
		//
		ans=0;
		for(int i=1;i<=n;++i){
			int fir=upper_bound(a+i+1,a+n+1,a[i]+d)-a;//找第一个不可达点
			if(fir==n+1){
				continue;
			}
			int l=upper_bound(a+fir,a+n+1,a[fir-1]+d)-a,r=lower_bound(a+fir,a+n+1,a[fir]+d)-a;//midis = 2 的，一定是不可直达的点
			ans+=max(r-l+1,0);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		n=read();
		d=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		solve();
		print(ans);
		putchar('\n');
	}
	return 0;
}
/*

Input #1:

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

Output #1:

0
1

*/