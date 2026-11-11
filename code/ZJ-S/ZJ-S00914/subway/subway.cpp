#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,inf=3e15+5;
int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return f*sum;
}
void print(int x){
	if(x<10){
		putchar('0'+x);
		return ;
	}
	print(x/10);
	putchar(x%10+'0');
}
int C,n,m,d,q;
int w[N];
struct node{
	int v,t;
};
vector<node> g[N];
int mp[505][505];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=mp[j][i]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<505;i++){
		for(int j=0;j<505;j++){
			mp[i][j]=inf;
		}
		mp[i][i]=0;
	}
	C=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x,y;
			x=read();y=read();
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<g[i].size();x++){
			for(int y=0;y<g[i].size();y++){
				if(x==y) continue;
				int u=g[i][x].v,v=g[i][y].v;
				int t1=g[i][x].t,t2=g[i][y].t;
				mp[u][v]=mp[v][u]=min(mp[u][v],t1+t2);
			}
		}
	}
	floyd();
	while(q--){
		int x,y,ans=inf;
		x=read();y=read();
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].v,v=g[y][j].v;
				ans=min(ans,g[x][i].t+g[y][j].t+mp[u][v]);
			}
		}
		print(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
