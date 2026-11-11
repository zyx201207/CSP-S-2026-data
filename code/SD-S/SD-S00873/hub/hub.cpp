#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rd read()
int read(int u=0,bool f=false,char c=getchar()){
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}void wt(int x,char c){wt(x);putchar(c);}
const int N=110;
int sz[N],n,k,f[N],dis[N];
vector<int>e[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int x,int fa,int dep){
	dis[x]=min(dis[x],dep);
	for(int i:e[x]) if(i!=fa) dfs(i,x,dep+1);
}
void work(){
	n=rd;k=rd;int ans=n+1;
	for(int i=1;i<n;i++){
		int u=rd,v=rd;
		e[u].push_back(v);
		e[v].push_back(u);
	}for(int s=0;s<(1<<n);s++){
		for(int i=1;i<=n;i++) f[i]=i;int sz=0;
		for(int i=1;i<=n;i++) if(s>>i-1&1){
			sz++;
			for(int j:e[i]) if(s>>j-1&1)
				f[find(i)]=find(j);
			}
		int cnt=0;if(sz>k) continue;
		for(int i=1;i<=n;i++) if((s>>i-1&1)&&(find(i)==i)) cnt++;
		if(cnt>2) continue;int sum=0;
		for(int i=1;i<=n;i++) dis[i]=n+1;
		for(int i=1;i<=n;i++) if((s>>i-1)&1) dfs(i,i,0);
		for(int i=1;i<=n;i++) sum=max(sum,dis[i]);
		ans=min(ans,sum);
	}wt(ans,'\n');
	for(int i=1;i<=n;i++) e[i].clear();
} 
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=rd,T=rd;
	while(T--) work();
	return 0;
}/*
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
