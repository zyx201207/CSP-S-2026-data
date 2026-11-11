#include <bits/stdc++.h>
using namespace std;
const int N=525,M=125500;
long long c,n,m,d,q,k[N],w[M],t[5],a[5],x,y,dis[N][N];
struct Edge{
	long long vi,wi;
};
vector <Edge>e[N];
int main(long long s){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			if(j==2){
				e[a[j]].push_back({a[j-1],t[j]+t[j-1]});
				e[a[j-1]].push_back({a[j],t[j-1]+t[j]});
				dis[a[j]][a[j-1]]=t[j]+t[j-1];
				dis[a[j-1]][a[j]]=t[j-1]+t[j];
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int p=min(i,j)+1;p<max(i,j);p++){
				if(dis[min(i,j)][p]+dis[p][max(i,j)]>dis[min(i,j)][max(i,j)]){
					dis[min(i,j)][max(i,j)]=dis[min(i,j)][p]+dis[p][max(i,j)];
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			dis[i][e[i][j].vi]=0;
		}
	}
	
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
