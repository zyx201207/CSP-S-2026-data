#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
const int M=507;
int c,n,m,d,q;
int w[N];
vector<pair<int,int> > di[M];
vector<int> zhan[N];
// struct node{
// 	int v,w;
// };
// vector<node> G[N];
int dis[M][M],f[M][M];
int fid(int u,int x){
	int l=0,r=di[u].size()-1;
	while(l<=r){
		int mid=l+r>>1;
//		cout<<mid<<' '<<' '<<l<<' '<<r<<' '<<di[u][mid].first<<'\n';
		if(x==di[u][mid].first) return di[u][mid].second;
		else if(x<di[u][mid].first) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		f[i][i]=0;
		cin>>k;
		while(k--){
			int ai,ti;
			cin>>ai>>ti;
			di[i].push_back({ai,ti});
			zhan[ai].push_back(i);//xian lu
			// G[0].push_back({i,w[ai]+ti});
			// f[0][i]=w[ai]+ti;
		}
		sort(di[i].begin(),di[i].end());
	}
	
	for(int i=1;i<=m;i++){
		int kkk=zhan[i].size();
		if(kkk<=1) continue;
		for(int u=0;u<kkk;u++){
			for(int v=u+1;v<kkk;v++){
				int cost=fid(zhan[i][u],i)+fid(zhan[i][v],i);
				// G[zhan[i][u]].push_back({zhan[i][v],cost});
				// G[zhan[i][v]].push_back({zhan[i][u],cost});
				f[zhan[i][u]][zhan[i][v]]=cost;
				f[zhan[i][v]][zhan[i][u]]=cost;
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
		int x,y;
		cin>>x>>y;
		int kkk=zhan[x].size(),kk=zhan[y].size(),ans=1e18;
		for(int u=0;u<kkk;u++){
			for(int v=0;v<kk;v++){
				int cost=fid(zhan[x][u],x)+fid(zhan[y][v],y);
//				cout<<zhan[x][u]<<' '<<zhan[y][v]<<' '<<cost<<'\n';
				ans=min(ans,w[x]+w[y]+cost+f[zhan[x][u]][zhan[y][v]]);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
froepen
chzx_AT AK NGOI !!!!!
*/