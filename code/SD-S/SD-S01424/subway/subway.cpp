#include<iostream>
#include<algorithm>
#define N 2000010
#define INF 1145141919810000
using namespace std;
long long head[N],ver[N],Next[N],val[N],tot=-1;
void add(long long x,long long y,long long z){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
	val[tot]=z;
}
long long n,m,d,q,w[N],dis[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		head[i]=-1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		long long tk;
		cin>>tk;
		if(tk==1){
			cin>>tk>>tk;
		}
		else{
			for(int j=1;j<=tk;++j){
				long long x,y;
				cin>>x>>y;
				add(x,i,y);
			}
		}
	}
	for(int k=1;k<=m;++k){
		for(int i=head[k];i!=-1;i=Next[i]){
			for(int j=head[k];j!=-1;j=Next[j]){
				long long x=ver[i],y=ver[j];
				dis[x][y]=min(dis[x][y],val[i]+val[j]);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long x,y,minn=INF;
		cin>>x>>y;
		for(int i=head[x];i!=-1;i=Next[i]){
			for(int j=head[y];j!=-1;j=Next[j]){
				minn=min(minn,val[i]+val[j]+dis[ver[i]][ver[j]]);
			}
		}
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
500 ->10000 s bian
20*500*500
*/
