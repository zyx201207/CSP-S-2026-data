#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],k[505];
struct xianlu{
	long long a;
	long long t;
}line[505][500005];
long long ans[100005],dis[500005][500005];
long long findway(long long x,long long y){
	if(dis[x][y]!=-1) return dis[x][y];
	long long o;
	for(long long i=1;i<=m;i++){
		if(i==x||i==y) continue;
		o=findway(x,i)+findway(i,y);
		if(dis[x][y]==-1) dis[x][y]=o;
		else if(o<dis[x][y]&&dis[x][y]!=-1) dis[x][y]=o;
	}
	return dis[x][y];
}
void f(long long i,long long x,long long y){
	ans[i]=ans[i]+w[x]+w[y];
	dis[x][y]=findway(x,y);
	ans[i]+=dis[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>line[i][j].a>>line[i][j].t;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			for(long long x=j+1;x<=k[i];x++){
				long long y=line[i][j].t+line[i][x].t;
				if(dis[j][x]>y||dis[x][j]>y){
					dis[j][x]=y;
					dis[x][j]=y;
				} 
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		f(i,x,y);
	}
	for(long long i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
