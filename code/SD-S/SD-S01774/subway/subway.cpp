#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e4+10;

int c,n,m,d,q;

int a[maxn][maxn],t[maxn][maxn],w[maxn],res=0;;

int dfs(int x,int y,int v){
	if(a[x][y]==v) return res;
	if(y==a[x][0] && a[x][y]!=v){
		res=0;
		return dfs(x+1,y,v);
	}
	res+=t[x][y];
	return dfs(x,y+1,v);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subawy.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i][0]=k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]==u){
					ans=dfs(i,j,v);
					break;
				}
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}
