#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5,M=500;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while ('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int pq,n,m,d,q_;
int w[N+5];
vector<pair<int,int> >a[M+5],t[N+5];
int dis[M+5][M+5];
void Add(int x,int y,int z){
	a[x].push_back(make_pair(y,z));
}
void Floyd(){
	for (int i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for (int k=1;k<=m;k++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				if (i==j || i==k ||	j==k){
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	pq=read();m=read();n=read();d=read();q_=read();
	for (int i=1;i<=n;++i){
		w[i]=read();
	}
	for (int i=1;i<=m;++i){
		int k=read();
		for (int j=1;j<=k;++j){
			int x=read();
			int z=read();
			t[x].push_back(make_pair(i,z));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++){
		for (int j1=0;j1<t[i].size();j1++){
			for (int j2=j1+1;j2<t[i].size();j2++){
				int y1=t[i][j1].first,z1=t[i][j1].second;
				int y2=t[i][j2].first,z2=t[i][j2].second;
				dis[y1][y2]=min(dis[y1][y2],z1+z2);
				dis[y2][y1]=min(dis[y2][y1],z1+z2);
			}
		}
	}
	Floyd();
//	for (int i=1;i<=m;i++){
//		cout<<i<<": ";
//		for (int j=1;j<=m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		puts("");
//	}
	while (q_--){
		int x,y;
		x=read();y=read();
		int ans=0x3f3f3f3f3f3f3f3f;
		for (int i=0;i<t[x].size();i++){
			for (int j=0;j<t[y].size();j++){
				int y1=t[x][i].first,z1=t[x][i].second;
				int y2=t[y][j].first,z2=t[y][j].second;
				ans=min(ans,dis[y1][y2]+z1+z2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
