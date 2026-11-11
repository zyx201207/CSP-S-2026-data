#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500100],a[600][600],g[600][600],b[600],b1[600][600],b2[600][600],k[600],t[600],l,r,ans=INT_MAX;
void dfs(int x,int y,int z){
	if(x==r){
		ans=min(ans,z);
		return;
	}
	for(int i=1;i<=t[x];i++){
		for(int j=b2[x][i]+1;j<=k[b1[x][i]];j++){
			if(b[a[i][j]]==0){
				b[a[i][j]]=1;
				if(i==y){
					dfs(a[i][j],i,z);
				}
				else{
					dfs(a[i][j],i,z+g[i][j]);
				}
				b[a[i][j]]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>g[i][j];
			b1[a[i][j]][++t[a[i][j]]]=i;
			b2[a[i][j]][t[a[i][j]]]=j;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		ans=INT_MAX;
		dfs(l,0,0);
		cout<<ans<<'\n';
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
*/