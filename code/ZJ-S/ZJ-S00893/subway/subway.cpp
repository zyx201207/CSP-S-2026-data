#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
vector<int> a[N],t[N];
bool vis[M];
struct node{
	int x,id,t;
};
vector<node> b[M];
int dfs(int u,int to){
	if(u==to) return 0;
	int res=1e18;
	for(node tmp:b[u]){//next subway
		for(int i=1;i<=k[tmp.x];i++){//next point
			if(vis[a[tmp.x][i]]) continue;
			vis[a[tmp.x][i]]=1;
			int _=tmp.t+t[tmp.x][i]+dfs(a[tmp.x][i],to);
			res=min(res,_);
			vis[a[tmp.x][i]]=0;
		}
	}
	return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		a[i].resize(k[i]+5);t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();t[i][j]=read();
			b[a[i][j]].push_back((node){i,j,t[i][j]});
		}
	}
	for(;q--;){
		int l=read(),r=read();
		vis[l]=1;
		write(w[l]+w[r]+dfs(l,r),'\n');
		vis[l]=0;
	}
	return 0;
}