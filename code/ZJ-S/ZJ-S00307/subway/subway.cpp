#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int res=0,ch;
	do{
		ch=getchar();
	}while(!isdigit(ch));
	do{
		res=(res<<1)+(res<<3)+(ch&0xf);
		ch=getchar();
	}while(isdigit(ch));
	return res;
}
constexpr int M=5e5+2,N=502;
constexpr ll inf=2e18;
int c,n,m,d,q,w[M];
vector<pair<int,int> > tingtai[M];
long long G[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j) G[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int a=read(),t=read();
			tingtai[a].push_back(make_pair(i,t));
		}
	}
	for(int x=1;x<=m;++x){//m=5e5...
		for(int i=0;i!=tingtai[x].size();++i){//d=20
			for(int j=0;j!=tingtai[x].size();++j){//d=20
				if(i==j) continue;
				int i1=tingtai[x][i].first,i2=tingtai[x][j].first;
				G[i1][i2]=min(G[i1][i2],(ll)tingtai[x][i].second+tingtai[x][j].second);
			}
		}
	}
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				G[i][j]=min(G[i][j],G[i][k]+G[j][k]);
			}
		}
	}
	
	while(q--){
		int x=read(),y=read();
		ll ans=inf;
		for(int i=0;i!=tingtai[x].size();++i){//d=20
			for(int j=0;j!=tingtai[y].size();++j){//d=20
				ans=min(ans,G[tingtai[x][i].first][tingtai[y][j].first]+tingtai[x][i].second+tingtai[y][j].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}