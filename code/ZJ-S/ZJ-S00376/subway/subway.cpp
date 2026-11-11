#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
int m,n,q,w[500005];
ll f[505][505];
vector<pair<int,ll> > b[500005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),t=read();
			b[x].push_back(make_pair(i,t));
		}
	}
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
//		printf("1\n");
		for(int j=0;j<b[i].size();j++)
		for(int k=j+1;k<b[i].size();k++){
			int x=b[i][j].first,y=b[i][k].first;
			ll wx=b[i][j].second,wy=b[i][k].second;
			f[x][y]=min(f[x][y],wx+wy);
			f[y][x]=min(f[y][x],wx+wy);
//			printf("%d %d %lld\n",x,y,wx+wy);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)if(f[i][k]!=INF)
	for(int j=1;j<=n;j++)
		if(f[k][j]!=INF&&f[i][j]>f[i][k]+f[k][j])
			f[i][j]=f[i][k]+f[k][j];
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=n;j++) printf("%lld%c",f[i][j],(j==n)?'\n':' ');
	while(q--){
		int x=read(),y=read();
//		printf("%d\n",b[y].size());
//		for(int i=0;i<b[y].size();i++) printf("%d\n",b[y][i].first);
		ll ans=1ll<<62;
		for(int i=0;i<b[x].size();i++)
		for(int j=0;j<b[y].size();j++){
//			if(i==j) continue;
//			printf("%d %d\n",i,j);
			int _x=b[x][i].first,_y=b[y][j].first;
//			if(_x==_y) continue;
//			printf("%d %d\n",x,y);
			ll wx=b[x][i].second,wy=b[y][j].second;
			if(f[_x][_y]!=INF) ans=min(ans,f[_x][_y]+wx+wy);
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
