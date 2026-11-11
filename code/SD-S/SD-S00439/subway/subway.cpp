#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=505,M=5005;
int c,n,m,d,q;
int w[500005],k[505],a[505][50005],t[505][50005];
int flag[M][N],flag2[M][N],idx[N];
int head[505*2],val[505*2],nex[505*2],wei[505*2],cnt=-1;
int gw[505][505],vis[505];
void add(int from,int to,int weight){
	val[++cnt]=to;
	nex[cnt]=head[from];
	head[from]=cnt;
	wei[cnt]=weight;
}
int dfsans=0x3f3f3f3f;
void dfs(int x,int to,int sum){
	if(x==to){
		dfsans=min(dfsans,sum);
		return;
	}
	if(x>n){
		return;
	}
	vis[x]=1;
	for(int i=head[x];i!=-1;i=nex[i]){
		if(vis[val[i]]==0){
			dfs(val[i],to,sum+wei[i]);
		}
	}
	vis[x]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(gw,0x3f,sizeof(gw));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			flag[a[i][j]][++idx[a[i][j]]]=i;
			flag2[a[i][j]][i]=t[i][j]; 
		}
	}
	for(int i=1;i<=m;i++){
		if(idx[i]<2)continue;
		for(int j=1;j<=idx[i];j++){ 
			for(int k=j+1;k<=idx[i];k++){
				gw[flag[i][j]][flag[i][k]]=min(gw[flag[i][j]][flag[i][k]],flag2[i][flag[i][j]]+flag2[i][flag[i][k]]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(gw[i][j]!=0x3f3f3f3f){
				add(i,j,gw[i][j]);
				add(j,i,gw[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy,minn=0x3f3f3f3f,bb=0;
		scanf("%d %d",&xx,&yy);
		dfsans=0x3f3f3f3f;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=idx[xx];j++){
			for(int k=1;k<=idx[yy];k++){
				dfs(flag[xx][j],flag[yy][k],flag2[xx][flag[xx][j]]+flag2[yy][flag[yy][k]]);
				minn=min(minn,dfsans);
			}
		}
		printf("%d\n",minn+w[xx]+w[yy]);
	}
	return 0;
}
