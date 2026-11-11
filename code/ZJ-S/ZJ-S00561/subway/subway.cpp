#include<bits/stdc++.h>
#define int long long
const int inf=1e18+7;
using namespace std;
int c,n,m,d,q;
const int N=505;
const int M=5e5+5;
int dis[N][N];
int w[M];
vector< pair<int,int> > vc[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vc[a].push_back({i,t});
		}
	}
//	cerr<<1<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			dis[i][j]=inf;
		}
//		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto it:vc[i]){
			for(auto jt:vc[i]){
				int i=it.first;
				int j=jt.first;
				if(i==j)continue;
				dis[i][j]=dis[j][i]=it.second+jt.second;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto it:vc[x]){
			for(auto jt:vc[y]){
				ans=min(ans,dis[it.first][jt.first]+it.second+jt.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
dui yu liang ge di tie xian lu
cong na li huan cheng dou shi yi yang de
suo yi dis[u][v] biao shi cong xian lu u dao xian lu v de zui duan ju li
ran hou floyd?
Maybe

da yang li quan guo,wo chu xi le!!!
*/

