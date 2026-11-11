#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,q,w[1005],a[505][1005],t[505][1005],k[505],xr,yr;
int bj[1005],res=1e9;
vector<int> g[1005];
void dfs(int x,int ti){
	if(x==yr){
		res=min(res,ti+w[yr]);
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		if(bj[g[x][i]]) continue;
		bj[g[x][i]]=1;
		dfs(g[x][i],ti+t[x][x]+t[x][g[x][i]]);
		bj[g[x][i]]=0;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
			if(j>1){
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	while(q--){
		res=1e9;
		memset(bj,0,sizeof(bj));
		xr=read();
		yr=read();
		bj[xr]=1;
		dfs(xr,w[xr]);
		cout<<res<<"\n";
	}
	return 0;
}