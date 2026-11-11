#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=5e5+30;
int c,n,m,dd,q;
ll d[365][365],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c<=6){
		scanf("%d%d%d%d",&n,&m,&d,&q);
		for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(i!=j)d[i][j]=1e12;
				else d[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			while(k--){
				int v;
				ll w;
				scanf("%d%lld",&v,&w);
				int u=i+m;
				d[u][v]=w;
				d[v][u]=w;
			} 
		} 
		for(int k=1;k<=n+m;k++){
			for(int i=1;i<=n+m;i++){
				for(int j=1;j<=n+m;j++){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			cout<<w[x]+w[y]+d[x][y]<<"\n";
		}
	}
	return 0;
}
