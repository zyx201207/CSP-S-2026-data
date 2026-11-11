#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
long long w[M];

struct node{
	int v;
	long long w;
}t[M][25];
int cnt[M];

long long dis[N][N];

void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			long long b;
			cin>>a>>b;
			t[a][++cnt[a]]={i,b};
		}
		
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=dis[j][i]=2e18;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				node p=t[i][j],q=t[i][k];
				dis[p.v][q.v]=min(dis[p.v][q.v],p.w+q.w);
				dis[q.v][p.v]=dis[p.v][q.v];
			}
		}
	}
	
	floyd();
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=2e18;
		for(int j=1;j<=cnt[x];j++){
			for(int k=1;k<=cnt[y];k++){
				node p=t[x][j],q=t[y][k];
				ans=min(ans,dis[p.v][q.v]+p.w+q.w);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}