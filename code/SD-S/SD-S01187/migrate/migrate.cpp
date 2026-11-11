#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2000100;
int c,T,x[N],n,d,dis[N],num[N];
bool vis[N];
vector<int>g[N];
int read(){
	int x=0;
	int f=1; 
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void bfs(int st){
	queue<int>q;
	q.push(st);
	vis[st]=1;dis[st]=0;
	while(!q.empty()){
		int p=q.front();
		vis[p]=0;
		q.pop();
		for(int e:g[p]){
			if(dis[e]>dis[p]+1){
				dis[e]=dis[p]+1;
				num[e]=1;
				if(!vis[e]){
					q.push(e);
					vis[e]=1;
				}
			}
			else if(dis[e]==dis[p]+1){
				num[e]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			g[i].clear();
			x[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					g[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			memset(num,0,sizeof(num));
			bfs(i);
			for(int i=1;i<=n;i++){
				if(num[i]==2)ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
