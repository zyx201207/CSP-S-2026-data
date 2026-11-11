#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int c,n,m,d,q;
int w[500005];
int G[505][505];
map<int,int> flag[500005];
vector<int> lists[505];
vector<int> lists2[500005];
int solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(G[i][j]+G[j][k]<G[i][k]){
					G[i][k]=G[i][j]+G[j][k];
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++){
			G[i][j]=LONG_LONG_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			flag[a][i]=t;//车站--线=时间
			lists[i].push_back(a);
			lists2[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		G[i][i]=0;
		for(int tmp=0;tmp<lists[i].size();tmp++){
			int x=lists[i][tmp];
			for(int tmp2=0;tmp2<lists2[x].size();tmp2++){
				int j=lists2[x][tmp2];
				if(flag[x][j]&&flag[x][i]){
					G[i][j]=G[j][i]=min(G[i][j],flag[x][i]+flag[x][j]);
				}
			}
		}
	}
	solve();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=LONG_LONG_MAX;
		for(int tmp1=0;tmp1<lists2[x].size();tmp1++){
			for(int tmp2=0;tmp2<lists2[y].size();tmp2++){
				int u=lists2[x][tmp1];
				int v=lists2[y][tmp2];
				ans=min(ans,flag[x][u]+flag[y][v]+G[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
//finish at 17:25
//expect=100
