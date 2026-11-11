#include<bits/stdc++.h>
using namespace std;
//Oct31==Dec25?
struct node{
	long long aa,t;
};
long long c,n,m,d,q,w[500005],a,t,f[505][505],x,y,k;
vector<node> v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			v[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int len=v[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				f[v[i][j].aa][v[i][k].aa]=min(f[v[i][j].aa][v[i][k].aa],v[i][j].t+v[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int xx=v[x][i].aa,yy=v[y][j].aa;
				ans=min(ans,f[xx][yy]+v[x][i].t+v[y][j].t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
