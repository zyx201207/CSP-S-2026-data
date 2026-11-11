#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7,M=2e6+7;
int c,T,tot,n,len,j,ma,i,k,u,cnt,v,now,to,st,res;
int head[N],dis[N],vis[N],pr[N],lst[N],flag[N];
struct no{
	int nxt,to;
}a[M];
struct nx{
	int id,val;
}b[N];
void add(int x,int y){
	a[++tot]=(no){head[x],y};
	head[x]=tot;
}
void dfs(int u,int f){
	for(int i=head[u];i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f) continue;
		if(!vis[v]) continue;
		flag[v]=1;
		dfs(v,u);
	}
}
void dfsval(int u,int f){
	int i;
	for(i=head[u];i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f||vis[v]) continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfsval(v,u);
	}
}
void sc(int now,int m){
	if(m>k) return;
	if(m==k||now>n){
		if(m!=k) return ;
		cnt=0;
		for(i=1;i<=n;i++) flag[i]=0,dis[i]=1e9;
		for(i=1;i<=n;i++)
			if(!flag[i]&&vis[i]){
				flag[i]=1,cnt++,dfs(i,0);
				if(cnt>2) break;
			}
		if(cnt>2) return ;
		res=0;
		for(i=1;i<=n;i++)
			if(vis[i]) dis[i]=0,dfsval(i,0);
		for(i=1;i<=n;i++)
			res=max(res,dis[i]);
		ma=min(ma,res);
		return ;
	}
	vis[now]=1;
	sc(now+1,m+1);
	vis[now]=0;
	sc(now+1,m);
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ma=1e18;
		for(i=1;i<=n;i++) head[i]=0,vis[i]=0;
		for(i=1;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
		sc(1,0);
		cout<<ma<<"\n";
	}
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
*/
