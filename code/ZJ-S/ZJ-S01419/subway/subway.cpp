#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
struct node{
	int v,w;
};
int c,n,m,d,q;
int a[500010],f[510][510];
vector<node>g[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int v=read(),w=read();
			g[v].push_back({i,w});
		}
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			f[i][j]=1e19;
			if(i==j){
				f[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j;k<g[i].size();k++){
				f[g[i][j].v][g[i][k].v]=min(f[g[i][j].v][g[i][k].v],g[i][j].w+g[i][k].w);
				f[g[i][k].v][g[i][j].v]=f[g[i][j].v][g[i][k].v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					f[j][i]=f[i][j];
				}
			}
		}
	}
	while(q--){
		int x=read(),y=read(),ans=1e19;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,f[i.v][j.v]+i.w+j.w+a[x]+a[y]);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}