#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+7;


namespace ImTrying{
	//bool M1;
	int w[N];
	int c,n,m,d,q;
	//int t[N][503];
	struct node{
		int id,t;
	};
	vector<node>tt[N];
	long long G[503][503];
	//bool M2;
	void work(){
		//auto t1=clock_t(0);
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G[i][j]=1e13;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int pos,T;
				cin>>pos>>T;
				//t[pos][i]=T;
				tt[pos].push_back({i,T});
			}
			G[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<(int)tt[i].size();j++){
				for(int k=j+1;k<(int)tt[i].size();k++){
					int pos1=tt[i][j].id,pos2=tt[i][k].id;
					G[pos1][pos2]=min(G[pos1][pos2],(long long)tt[i][j].t+tt[i][k].t);
					G[pos2][pos1]=min(G[pos2][pos1],(long long)tt[i][j].t+tt[i][k].t);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=LONG_LONG_MAX;
			for(int i=0;i<(int)tt[x].size();i++){
				for(int j=0;j<(int)tt[y].size();j++){
					int pos1=tt[x][i].id,pos2=tt[y][j].id;
					long long res=G[pos1][pos2];
					res+=(long long)w[x]+w[y]+tt[x][i].t+tt[y][j].t;
					ans=min(ans,res);
				}
			}
			cout<<ans<<"\n";
		}
		//cout<<((&M2)-(&M1))/1024.0/1024.0;
		//auto t2=clock_t(0);
		//cout<<(t2-t1)/CLOCKS_PER_SEC;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ImTrying::work();
	return 0;
}

