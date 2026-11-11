#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
#define pii pair<int,int>
int c,n,m,d,q;
const int inf=10000000000000009;
int dis[500010],k[510],a[510][1010],t[510][1010],w[500010];
vector<pii> edges[10000010];
void dij(int s){
	for(int i=1;i<=m*20;i++){
		dis[i]=inf;
	}
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		auto info=q.top();
		q.pop();
		int di=info.first;
		int u=info.second;
		if(dis[u]!=di)continue;
		for(auto ed:edges[u]){
			int v=ed.first;
			int w=ed.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	
} 
int cnt[500010];
signed main(){
//	cout<<system("fc subway.out /w subway3.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		a[i][1]=read();t[i][1]=read();
		++cnt[a[i][1]];
		edges[a[i][1]].emplace_back(a[i][1]+cnt[a[i][1]]*m,t[i][1]);
		edges[a[i][1]+cnt[a[i][1]]*m].emplace_back(a[i][1],t[i][1]);
		for(int j=2;j<=k[i];j++){
			a[i][j]=read();//当前点（原本编号） 
			t[i][j]=read();
			int v=a[i][j]+(++cnt[a[i][j]])*m; //a[i][j]的新点 
			edges[v].emplace_back(a[i][j-1]+cnt[a[i][j-1]]*m,0);
			edges[a[i][j-1]+(cnt[a[i][j-1]])*m].emplace_back(v,0);
			edges[a[i][j]].emplace_back(v,t[i][j]);
			edges[v].emplace_back(a[i][j],t[i][j]);
		}
	}
	while(q--){
		int x=read(),y=read();
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
