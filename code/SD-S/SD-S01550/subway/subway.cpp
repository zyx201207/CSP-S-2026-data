#include <bits/stdc++.h>
#define int long long
//#define MOD (1000000007)
//#define eps (1e-6)
#define debug cout<<"debug"<<endl;
#define endl '\n'
using namespace std;
const int MAXM=5e5+10; 
const int MAXN=510;
const int INF=0x7f7f7f7f7f7f7f7fll;
int c,n,m,d,q;
int w[MAXM],cnt[MAXN],f[MAXN][MAXN];
vector<pair<int,int>> subways[MAXM];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;++i){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];++j){
			int x,y;
			cin>>x>>y;
			subways[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=m;++i){
		for(int x=0;x<subways[i].size();++x){
			for(int y=x+1;y<subways[i].size();++y){
				int u=subways[i][x].first,v=subways[i][y].first,val=subways[i][x].second+subways[i][y].second;
				f[u][v]=min(f[u][v],val);
				f[v][u]=min(f[v][u],val);
			}
		}
	}
	for(int i=1;i<=n;++i) f[i][i]=0; 
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(f[i][k]!=INF&&f[k][j]!=INF&&f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		} 
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<endl;
//	} 
	for(int i=1;i<=q;++i){
		int x,y,ans=INF;
		cin>>x>>y;
		for(int s=0;s<subways[x].size();++s){
			for(int t=0;t<subways[y].size();++t){
				int u=subways[x][s].first,v=subways[y][t].first;
				if(f[u][v]!=INF){
					ans=min(ans,subways[x][s].second+f[u][v]+subways[y][t].second); 
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	} 
	return 0;
}
/*
uid:511811
得得得得
萨布为
神秘超长题面
15min
啥东西这是
读了7min题面
 0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
46min
测完了，和一位 
*/

