#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+1;
int c,n,m,d,q,w[M],to[N];
long long e[N][N];
vector<pair<int,int>>up[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	memset(e,127,sizeof(e));
	for(int i=1;i<=n;i++)e[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=k;j--;){
			int a,t;
			scanf("%d%d",&a,&t);
			up[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			memset(to,0,sizeof(to));
			for(pair<int,int>k:up[j])to[k.first]=k.second;
			if(to[i])
				for(pair<int,int>k:up[j])
					e[i][k.first]=min(e[i][k.first],1LL*to[i]+k.second);
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(e[i][k]>1LL<<60||e[k][j]>1LL<<60)continue;
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1LL<<60;
		for(pair<int,int>i:up[x])
			for(pair<int,int>j:up[y]){
				ans=min(ans,i.second+e[i.first][j.first]+j.second);
			}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
