#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
int a[505][20005];
int t[505][20005];
int b[20005][505];
int e[20005];
int k[20005];
int to[505][20005];
long long mi_ans=INT_MAX;
long long dfs(int x,int y,int l,long long ans,long long mi,int to[][20005]){
	if(x==y){
		for(int i=1;i<=k[l];i++){
			if(a[l][i]==y){
				return ans+t[l][i];
			}
		}
	}
	for(int i=1;i<=e[x];i++){
		if(b[x][i]!=l&&to[b[x][i]][x]==0){
			ans+=(long long)(t[l][x]+t[b[x][i]][x]);
			to[b[x][i]][x]=1;
			for(int j=1;j<=k[b[x][i]];j++){
				if(to[b[x][i]][a[b[x][i]][j]]==0){
					to[b[x][i]][a[b[x][i]][j]]=1;
					mi=min(dfs(a[b[x][i]][j],y,b[x][i],ans,mi,to),mi);
					to[b[x][i]][a[b[x][i]][j]]=0;
				}
			}
			to[b[x][i]][x]=0;
		}
	}
	for(int i=1;i<=k[l];i++){
		if(a[l][i]!=x&&to[l][a[l][i]]==0){
			to[l][a[l][i]]=1;
			mi=min(dfs(a[l][i],y,l,ans,mi,to),mi);
			to[l][a[l][i]]=0;
		}
	}
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]][++e[a[i][j]]]=i;
		}
	}
	while(q--){
		mi_ans=INT_MAX;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=e[x];i++){
			mi_ans=min(dfs(x,y,b[x][i],0,INT_MAX,to)+t[b[x][i]][x],mi_ans);
		}
		cout<<mi_ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
