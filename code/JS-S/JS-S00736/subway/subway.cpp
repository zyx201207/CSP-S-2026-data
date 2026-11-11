#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=5e5+5;
int n,m,d,q;
int w[MAXM];
vector<pair<int,int> > vec[MAXM];
int b[MAXM],c[MAXN],cnt;
long long dist[MAXN][MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&m,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		while(num--){
			int x,y;
			scanf("%d%d",&x,&y);
			vec[x].push_back({i,y});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cnt=0;
		for(auto j:vec[i]){
			cnt++;
			b[cnt]=j.first,c[cnt]=j.second;
		}
		for(int j=1;j<=cnt;j++){
			for(int k=j+1;k<=cnt;k++){
				dist[b[j]][b[k]]=min(dist[b[j]][b[k]],(long long)(c[j]+c[k]));
				dist[b[k]][b[j]]=min(dist[b[k]][b[j]],(long long)(c[j]+c[k]));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		long long ans=1e18;
		for(auto i:vec[l]){
			for(auto j:vec[r]){
				ans=min(ans,dist[i.first][j.first]+i.second+j.second);
			}
		}
		printf("%lld\n",ans+w[l]+w[r]);
	}
	return 0;
}