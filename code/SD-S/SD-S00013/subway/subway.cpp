#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int l,r;
int a[1001][1001],t[1001][1001];
int w[150000],op[12311];
bool vis[1001][1001];
int ans=0x3f3f3f3f;
void check(int s){
	ans=min(ans,s);
	return;
}
void dfs(int x,int y,int step){
	for(int i=1;i<=op[x];i++){
		if(a[x][i]==r){
			check(step+w[a[x][i]]+t[x][i]);
			return;
		}
		if(vis[x][i]==0){
			vis[x][i]=1;
			dfs(x,i,step);
			vis[x][i]=0;
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=op[i];j++){
			if(a[i][j]==a[x][y]&&(x!=i||j!=y)&&vis[i][j]==0){
				vis[i][j]=1;
				dfs(i,j,step+t[i][j]+t[x][y]);
				vis[i][j]=0;
				flag=1;
			}
		}
	}
	
	if(flag==1){
		for(int j=1;j<=op[x];j++){
			if(vis[x][j]==0&&j!=y){
				vis[x][j]=1;
				dfs(x,j,step);
				vis[x][j]=0;
			}
		}
	}
	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>op[i];
		for(int j=1;j<=op[i];j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	}	
	while(q--){
		ans=0x3f3f3f3f;
		scanf("%d%d",&l,&r);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=op[i];j++){
				if(a[i][j]==l){
					vis[i][j]=1;
					dfs(i,j,w[a[i][j]]+t[i][j]);
				}
				
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
