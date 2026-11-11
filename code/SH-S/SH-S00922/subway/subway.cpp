#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
#define int long long
typedef pair<int,int> pii;
const int MAX=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M];
vector<pii> a[M];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)	scanf("%lld",&w[i]);
	for(int v=1;v<=n;v++){
		int k;scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int u,ww;
			scanf("%lld%lld",&u,&ww);
			a[u].push_back({v,ww});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int u=1;u<=m;u++){
		for(pii ed1:a[u]){
			for(pii ed2:a[u]){
				int v1=ed1.first,v2=ed2.first;
				int w1=ed1.second,w2=ed2.second;
				if(v1>=v2)	continue;
				dis[v1][v2]=dis[v2][v1]=min(dis[v1][v2],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]==MAX||dis[k][j]==MAX)	continue; 
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==MAX)	cout<<-1;
//			else	cout<<dis[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;scanf("%lld%lld",&x,&y);
		int ans=MAX;
		for(pii ed1:a[x]){
			for(pii ed2:a[y]){
				int v1=ed1.first,v2=ed2.first;
				int w1=ed1.second,w2=ed2.second;
				ans=min(ans,w1+dis[v1][v2]+w2);
			}
		}
		ans+=(w[x]+w[y]);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);

//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

	return 0;
}
