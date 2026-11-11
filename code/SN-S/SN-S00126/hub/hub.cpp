#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,k,f[N][20],d[N],cnt,h[N];
struct node{
	int to,nxt;
}e[N*2];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa){
	f[x][0]=fa;
	d[x]=d[fa]+1;
	for(int i=1;i<=19;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa) dfs(v,x);
	}
}
int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(d[f[x][i]]>=d[y]) x=f[x][i];
	}
	if(x==y) return y;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		} 
	} 
	return f[x][0];
} 
int juli(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(h,0,sizeof(h));
		cnt=0;
		memset(e,0,sizeof(e));
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			add(x,y),add(y,x);
		}
		int ans=N*N;
		dfs(1,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int sum=0;
				if(i==j) continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum=max(sum,min(juli(k,i),juli(k,j)));
				} 
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
