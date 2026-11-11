#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int max1=0;
int w[500005];
int k[500005];
int a[501][100005],t[501][100005];
bool vis[501][100005];
int x,y;
int ct=0;
void dfs(int sum,int xian,int zhan){
	if(zhan==y){
		sum=sum+t[xian][zhan]+w[x]+w[y];
		cout<<sum;
		return;
	}
	for(int i=1;i<=k[xian];i++){
		if(a[xian][i]==zhan){
			if(i+1<=k[i]&&!vis[xian][a[xian][i+1]]){
				dfs(sum,xian,a[xian][i+1]);
				vis[xian][a[xian][i+1]]=true;

			}
				
			for(int j=1;j<=n;j++){
				if(j==xian)
					continue;
				for(int r=1;r<=k[j];r++)
					if(a[j][r]==zhan&&!vis[j][zhan]){
						dfs(sum+t[xian][zhan]+t[j][zhan],j,zhan);
						vis[j][zhan]=true;
					}
						
			}
			break;
		}
	}
	
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][a[i][j]]);
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++)
			for(int r=1;r<=m;r++)
				vis[j][r]=0;
		int xian;
		scanf("%d%d",&x,&y);
		for(int j=1;j<=n;j++){
			for(int r=1;r<=k[j];r++)
				if(a[i][r]==x){
					xian=i;
				}
		}
		dfs(0,xian,x);
	}
	
	return 0;
}