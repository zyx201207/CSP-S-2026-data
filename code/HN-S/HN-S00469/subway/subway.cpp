#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e2+20,M=5e3+20;
struct Edge{
	int x,y,w;
}g[N*M];

struct Line{
	int num,t;
}l[N][M];

int c,n,m,d,q;
int w[M],k[N];
LL r[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int num,t;
			cin>>num>>t;
			l[i][j]={num,t};
		}
	}
	while(q--){
		LL ans=0;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(x==l[i][j].num || y==l[i][j].num) r[l[i][j].num]+=(w[l[i][j].num]+l[i][j].t);
				else r[l[i][j].num]+=l[i][j].t;
			}
		}
		for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			g[i]={l[i][j].num,l[i][j-1].num,r[l[i][j].num]+r[l[i][j-1].num]};
		}
	  }
	  for(int i=x;i<=y;i++){
	  	ans+=g[i].w;
	  }
	  cout<<ans<<endl;
	  memset(g,0,sizeof(g));
	  memset(r,0,sizeof(r));
	}
	
	return 0;
}
