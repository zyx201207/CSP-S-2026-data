#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,l;
};
int n,m,w[500005],d,q,dis[505][505],inf=0x3f3f3f3f3f3f3f3f,c;
vector<node> p[500005];
int get(){
	int l=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		l=l*10+c-'0';
		c=getchar();
	}
	return l;
}
void print(int x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	c=get();n=get();m=get();d=get();q=get();
	for(int i=1;i<=m;i++)w[i]=get();
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k=get();
		for(int j=1;j<=k;j++){
			int v=get(),t=get();
			p[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<p[i].size();u++){
			for(int v=u+1;v<p[i].size();v++){
				dis[p[i][u].v][p[i][v].v]=min(dis[p[i][u].v][p[i][v].v],p[i][u].l+p[i][v].l);
				dis[p[i][v].v][p[i][u].v]=dis[p[i][u].v][p[i][v].v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k||dis[i][k]==inf)continue;
			for(int j=i+1;j<=n;j++){
				if(j==k||dis[k][j]==inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u=get(),v=get(),ans=inf;
		for(int j=0;j<p[u].size();j++){
			for(int k=0;k<p[v].size();k++){
				ans=min(ans,dis[p[u][j].v][p[v][k].v]+p[u][j].l+p[v][k].l);
			}
		}
		print(ans+w[u]+w[v]);
		putchar('\n');
	}
	return 0;
}
