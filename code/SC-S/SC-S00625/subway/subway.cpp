#include<bits/stdc++.h>
using namespace std;
const int N=505,M=10005,Q=1e5+10;
const int INF=2e9;
int c,n,m,d,q;
int t;
int ww[N];
int u[N],v[N];
int li[N][N];
int dis[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	if(7<=c&&c<=11)ww[1]=1;
	else if(12<=c&&c<=19){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
		int tot=1;
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			int a,la;
			cin>>la>>t;
			for(int j=2;j<=k;j++){
				li[i][j]=la;
				cin>>a>>t;
				u[tot]=la;
				v[tot]=a;
				++tot;
				la=a;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					dis[i][j]=min(min(dis[i][j],dis[i][k]+dis[k][j]-2*t),2*t);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(abs(x-y)==1){cout<<2*t;return 0;}
			cout<<dis[x][y]<<endl;
		}
	}
	return 0;
}