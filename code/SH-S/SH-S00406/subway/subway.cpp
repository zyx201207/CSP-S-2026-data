#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long v,w;
};
vector<edge> rec[500009];
long long c,n,m,d,q,x,y,w[500009],dist[509][509];
long long read(){
	long long ret=0,ty=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ty=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		ret=ret*10+c-'0',c=getchar();
	return ret*ty;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(long long i=1;i<=m;i++)
		w[i]=read();
	for(long long i=1;i<=n;i++){
		fill(dist[i]+1,dist[i]+n+1,1e16);
		dist[i][i]=0;
		long long k=read();
		while(k--){
			long long a=read(),t=read();
			rec[a].push_back({i,t});
		}
	}
	for(long long i=1;i<=m;i++)
		for(long long ii=0;ii<rec[i].size();i++)
			for(long long jj=0;jj<rec[i].size();jj++)
				dist[rec[i][ii].v][rec[i][jj].v]=min(dist[rec[i][ii].v][rec[i][jj].v],rec[i][ii].w+rec[i][jj].w);
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(dist[i][k]!=1e16&&dist[k][j]!=1e16)
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		x=read(),y=read();
		long long ans=1e16;
		for(long long i=0;i<rec[x].size();i++)
			for(long long j=0;j<rec[y].size();j++)
				ans=min(ans,dist[rec[x][i].v][rec[y][j].v]+rec[x][i].w+rec[y][j].w);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} 
