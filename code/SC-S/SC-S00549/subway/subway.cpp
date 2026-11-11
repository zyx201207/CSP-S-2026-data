#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=6e5+10;
int c,n,m,d,q;
ll Z_t[maxn];
vector<pair<int,ll>> H[maxn];
ll len[510][510];
ll M=LONG_LONG_MAX;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>Z_t[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int z,t;
			
			cin>>z>>t;
			H[z].push_back({i,t});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			len[i][j]=M;
			
		}
	}
	
	for(int i=1;i<=m;i++){
		for(auto t_1:H[i]){
			for(auto t_2:H[i]){
				int x_1=t_1.first;
				ll cost_1=t_1.second;
				int x_2=t_2.first;
				ll cost_2=t_2.second;
				if(x_1==x_2)continue;
				len[x_1][x_2]=min(len[x_1][x_2],cost_1+cost_2);
				len[x_2][x_1]=min(len[x_1][x_2],len[x_2][x_1]);
				
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(len[i][k]!=M&&len[k][j]!=M){
					len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		ll ans=M;
		
		for(auto t_1:H[u]){
			for(auto t_2:H[v]){
				int x_1=t_1.first;
				ll cost_1=t_1.second;
				int x_2=t_2.first;
				ll cost_2=t_2.second;
				
				ans=min(ans,cost_1+cost_2+len[x_1][x_2]);
				
			}
		}
		ans+=Z_t[u]+Z_t[v];
		cout<<ans<<'\n';
	}

	return 0;
}