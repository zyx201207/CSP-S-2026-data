#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1000,M=1e6+1e5,E=1020;
int head[M],vis[M],a[N],t[N];
long long c,n,m,d,q,w[N],l,cnt=0,ans[E][E],z[M],x,y;
struct nn{
	long long w,x;
	 bool operator < (const nn q)const { 
		return q.w<w;
	}
};
priority_queue <nn> qu;
struct node{
	long long nxt,to,w;
}edge[M];
void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].w=w;
	head[x]=cnt;
}
void dij(int x,int g){
	qu.push(nn{0,x});
	ans[x][x]=0;
	z[x]=0;
	while(!qu.empty()){
		nn tp=qu.top();
		qu.pop();
		if(vis[tp.x]) continue;
		vis[tp.x]=1;
		for(int i=head[tp.x];i;i=edge[i].nxt){
			if(z[edge[i].to]>z[tp.x]+edge[i].w){
				z[edge[i].to]=z[tp.x]+edge[i].w;
				if(edge[i].to<=m){
					ans[edge[i].to][g]=min(ans[edge[i].to][g],z[tp.x]+edge[i].w);
					ans[g][edge[i].to]=min(ans[g][edge[i].to],z[tp.x]+edge[i].w);
				}
				
				qu.push(nn{ans[edge[i].to][g],edge[i].to});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a[j]>>t[j];
			add(m*i+a[j],a[j],t[j]);
			add(a[j],m*i+a[j],t[j]);
			if(j>=2){
				add(m*i+a[j],m*i+a[j-1],0);	
				add(m*i+a[j-1],m*i+a[j],0);	
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=m;i++){
			ans[i][j]=LONG_LONG_MAX;
		}
	}
	for(int j=1;j<=m*(n+1);j++) z[j]=LONG_LONG_MAX;
	for(int i=1;i<=m;i++){
		dij(i,i);
		for(int j=1;j<=m*(n+1);j++){
			vis[j]=0;z[j]=LONG_LONG_MAX;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<ans[y][x]+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 3 20 2
4 1 9
2 1 5 2 7
2 2 3 3 4
1 3
2 3


*/