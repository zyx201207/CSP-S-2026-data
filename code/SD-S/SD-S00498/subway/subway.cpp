#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll INF=1e18;
const int N=507;
const int M=5e5+7;
int c,n,m,d,q,w[M];
ll bq[N][N];
struct sta{int id,t;};
vector<sta> INC[M]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int id,t;cin>>id>>t;
			INC[id].push_back(sta{i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) bq[i][j]=bq[j][i]=INF;
	for(int i=1;i<=n;i++) bq[i][i]=0ll;
	for(int i=1;i<=m;i++){
		for(auto nw1:INC[i]){
			for(auto nw2:INC[i]){
				if(nw1.id==nw2.id) continue;
				bq[nw1.id][nw2.id]=bq[nw2.id][nw1.id]=min(bq[nw1.id][nw2.id],1ll*nw1.t+1ll*nw2.t);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++) bq[i][j]=bq[j][i]=min(bq[i][j],bq[i][k]+bq[k][j]);
	while(q--){
		int u,v;cin>>u>>v;
		ll Ans=INF;
		for(auto nw1:INC[u])
			for(auto nw2:INC[v]){
				ll lsbl=1ll*nw1.t+1ll*nw2.t+bq[nw1.id][nw2.id];
				Ans=min(Ans,lsbl);
			}
		cout<<Ans+1ll*w[u]+1ll*w[v]<<"\n";
	}
	return 0;
}
