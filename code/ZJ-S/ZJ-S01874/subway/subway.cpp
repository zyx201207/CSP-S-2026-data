#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int M=5e5+3;
const int INF=1e17+9;
int w[M],cnt[M];//cnt[i]:di i tiaoxianlubeijngguojici
struct Node{
	int number,t;
}a[30][M];//a[i][j] : di a[i][j].number tiaoxianlu dexiayizhanshi a[i][j].to/daozhantaiyao a[i][j].t deshijian
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;int x,y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[++cnt[x]][x].number=i;
			a[cnt[x]][x].t=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				dis[a[j][i].number][a[k][i].number]=min(dis[a[j][i].number][a[k][i].number],a[j][i].t+a[k][i].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==INF)continue;
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,a[i][x].t+a[j][y].t+dis[a[i][x].number][a[j][y].number]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
//1 ≤ m ≤n*(n-1)/2 k ≤ 5e5，1 ≤ d ≤ 20，1 ≤ q ≤ 105 500*500=250000
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
floyd play!!!
16:20 100pts
*/