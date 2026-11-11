#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}
const int N=510,M=5e5+10,inf=1e18;
int a[M],dis[N][N];
vector<pair<int,int> > e[M]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=inf;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),y=read();
			e[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		int len=e[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=e[i][j].first,v=e[i][k].first;
				dis[u][v]=dis[v][u]=min(dis[u][v],e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read(),ans=inf;
		for(auto i:e[x]){
			for(auto j:e[y]){
				int u=i.first,v=j.first;
				ans=min(ans,dis[u][v]+i.second+j.second);
			}
		}
		cout <<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
/*

Floyd

O(n^3 + q d^2 + \sum d^2)

be done on 15:32

about 2s (local)

notice MLE

*/
