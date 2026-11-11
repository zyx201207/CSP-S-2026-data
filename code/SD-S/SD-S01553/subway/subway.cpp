#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=500010;
const long long inf=1e18;
int w[M];
vector<pair<int,int>> v[M];
long long c[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,k,x,t;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&t);
			v[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i!=j){
			c[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto it1:v[i]){
			int a=it1.first,w1=it1.second;
			for(auto it2:v[i]){
				int b=it2.first,w2=it2.second;
				if(a!=b){
					c[a][b]=min(c[a][b],0ll+w1+w2);
					c[b][a]=min(c[b][a],0ll+w1+w2);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		long long ans=inf;
		for(auto it1:v[x]){
			int a=it1.first,w1=it1.second;
			for(auto it2:v[y]){
				int b=it2.first,w2=it2.second;
				ans=min(ans,w[x]+w1+c[a][b]+w2+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
