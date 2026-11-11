#include<bits/stdc++.h> 
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int G[505][505];
vector<int> a[505];
map<int,int> att[505];
vector<int> t[505];
vector<int> mi[505];//每条线路的最小的站台到站厅时间标号 
vector<int> st[500005];//每个站点的所有列车 
map<int,int> stt[500005];//每个站点走到所有列车站台的时间 

const int INF=0x3f3f3f3f3f3f3f3f;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			G[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int mii=INF;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			mii=min(mii,t1);
			a[i].push_back(a1);
			att[i][a1]=t1;
			st[a1].push_back(i);
			stt[a1][i]=t1;
			t[i].push_back(t1);
		}
		for(int j=0;j<k;j++){
			if(t[i][j]==mii)mi[i].push_back(j);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(i==j){
//				G[i][j]=0;
//				continue;
//			}
////			for(int ii=0;ii<a[i].size();ii++){
////				for(int jj=0;jj<a[j].size();jj++){
////					if(a[i][ii]==a[j][jj]){
////						G[i][j]=min(G[i][j],t[i][ii]+t[j][jj]);
////						G[j][i]=min(G[j][i],t[i][ii]+t[j][jj]);
////					}
////				}
////			}
//			
//			for(int ii=0;ii<a[i].size();ii++){
//				if(att[j][a[i][ii]]==0)continue;
//				G[i][j]=min(G[i][j],t[i][ii]+att[j][a[i][ii]]);
//				G[j][i]=min(G[j][i],t[i][ii]+att[j][a[i][ii]]);
//			}
//		}
//	}
	
	for(int k=1;k<=m;k++){
		for(int j:st[k]){
			for(int i:st[k]){
				if(i==j){
					G[i][j]=0;
					continue;
				}
				G[i][j]=min(G[i][j],stt[k][i]+stt[k][j]);
				G[j][i]=min(G[j][i],stt[k][i]+stt[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=INF;
		for(int i=0;i<(int)st[x].size();i++){
			for(int j=0;j<(int)st[y].size();j++){
				//if(st[x][i]==st[y][j])continue;
				ans=min(ans,G[st[x][i]][st[y][j]]+w[x]+w[y]+stt[x][st[x][i]]+stt[y][st[y][j]]);
				//cout<<G[st[x][i]][st[y][j]]+w[x]+w[y]+stt[x][st[x][i]]+stt[y][st[y][j]]<<' '<<stt[x][st[x][i]]<<' '<<stt[y][st[y][i]]<<' '<<w[x]+w[y]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
