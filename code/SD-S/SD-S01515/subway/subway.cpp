#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
inline long long read(){
	long long res=0,f=1;char g=getchar();
	while(g<'0'||g>'9'){if(g=='-'){f=-1;}g=getchar();}
	while(g>='0'&&g<='9'){res=(res<<3)+(res<<1)+g-48;g=getchar();}
	return res*f;
}
int c,n,m,d,Q;
long long w[500010];
long long q[510][510];
vector <pair<int,long long>> a[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				q[i][j]=1e18;
	for(int i=1;i<=m;i++)w[i]=read();
	int k1,a1,t1;
	for(int i=1;i<=n;i++){
		k1=read();
		for(int j=1;j<=k1;j++){
			a1=read(),t1=read();
			a[a1].push_back({i,t1});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=0;k<a[i].size();k++){
				if(j==k)continue;
				q[a[i][j].first][a[i][k].first]=min(q[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				//printf("%d %d %d %d %d %d\n",i,j,k,q[i][k],q[j][k],q[i][j]);
				if(q[i][k]!=1e18&&q[j][k]!=1e18&&q[i][j]>q[i][k]+q[j][k]){
					q[i][j]=q[i][k]+q[j][k];
					q[j][i]=q[i][k]+q[j][k];
					//printf("%d %d %d %d %d %d\n",i,j,k,q[i][k],q[j][k],q[i][j]);
				}
			}
		}
	}
	int x,y;
	long long minn=1e18;
	while(Q--){
		x=read(),y=read();
		minn=1e18;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				minn=min(minn,a[x][i].second+a[y][j].second+q[a[x][i].first][a[y][j].first]);
			}
		}
		printf("%lld\n",w[x]+w[y]+minn);
	}
	return 0;
}


