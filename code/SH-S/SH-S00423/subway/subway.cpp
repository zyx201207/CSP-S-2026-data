#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MaxM=5e5+5,MaxN=5e2+5,INF=1e16;

int C,n/*线路数*/,m/*站点数*/,D,Q;
int W[MaxM];
vector <pair<int,int> > line[MaxM]/*节点i连接了那些线路*/;
int dis[MaxN][MaxN];

void chkmin(int &x,int y){
	x=(x<y?x:y);
	return ;
}
int read(){
	char c=getchar();
	int f=0;
	while(c<'0' or c>'9') c=getchar();
	while(c>='0' and c<='9'){
		f=f*10+c-'0';
		c=getchar();
	}
	return f;
}
void print(int x){
	if(x>9) print(x/10);
	putchar((char)(x%10+'0'));
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();
	n=read();
	m=read();
	D=read();
	Q=read();
	for(int i=1;i<=m;i++) W[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,a,t;j<=k;j++){
			a=read();
			t=read(); 
			line[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int id=1;id<=m;id++){
		for(pair<int,int> i:line[id]){
			int u=i.first;
			for(pair<int,int> j:line[id]){
				int v=j.first;
				chkmin(dis[u][v],i.second+j.second);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int st,ed;Q;Q--){
		cin>>st>>ed;
		int ans=W[st]+W[ed];
		int res=INF;
		for(pair<int,int> i:line[st]){
			for(pair<int,int> j:line[ed]){
				int u=i.first,v=j.first;
				chkmin(res,dis[u][v]+i.second+j.second);
			}
		}
		print(ans+res);
		cout<<endl;
	}
	return 0;
}
